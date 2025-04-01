import struct
import socket
from error import (ComandoNaoReconhecido, HostInvalido, ServerError)

def valid_commands(): 
  return ['itr', 'itv', 'gtr', 'gtv']

INDIVIDUAL_TOKEN_REQUEST = 1
INDIVIDUAL_TOKEN_VALIDATION = 3
GROUP_TOKEN_REQUEST = 5
GROUP_TOKEN_VALIDATION = 7

def check_for_error(response):
  """ Verifica se a resposta do servidor contém um erro e lança uma exceção. """
  if len(response) == 4:
    message_type, error_code = struct.unpack("!HH", response[:4])  # 2-byte int + 2-byte int
    if message_type == 256:
      raise ServerError(error_code)

def ipv4oripv6(host, port):
  addr_info = socket.getaddrinfo(host, port, 0, socket.SOCK_DGRAM)
  available = [(info[0], info[4]) for info in addr_info]

  if len(available) == 0:
      raise HostInvalido(host, port)

  for type in (socket.AF_INET, socket.AF_INET6):
    try:
        socket.inet_pton(type, host)
        if type in [conn[0] for conn in available]:
            return type, host
    except socket.error:
        pass

  raise HostInvalido(host, port)

def encode_message(command, args):
  if(command == 'itr'):
    req_id = args[0]
    req_nonce = args[1]

    return struct.pack("!h12si", INDIVIDUAL_TOKEN_REQUEST, req_id.encode("ascii"), int(req_nonce))
  elif(command == 'itv'):
    sas = args[0]
    req_id, req_nonce, req_token = sas.split(":")

    return struct.pack("!h12si64s", INDIVIDUAL_TOKEN_VALIDATION, req_id.encode("ascii"), int(req_nonce), req_token.encode("ascii"))
  elif(command == 'gtr'):
    n = int(args[0])
    req_gas = args[1:]

    req_sas = []
    for sas in req_gas:
      req_id, req_nonce, req_token = sas.split(":")
      req_sas.append(struct.pack("!12sI64s", req_id.encode("ascii"), int(req_nonce), req_token.encode("ascii")))

    return struct.pack(f"!hh{'80s' * n}", GROUP_TOKEN_REQUEST, n, *req_sas)
  elif (command == 'gtv'):
    req_gas = args[0]
    req_gas_token = req_gas.split("+")[-1]
    group_member_sas = req_gas.split("+")[:-1]
    n = len(group_member_sas)

    req_sas = []
    for sas in group_member_sas:
      req_id, req_nonce, req_token = sas.split(":")
      req_sas.append(struct.pack("!12si64s", req_id.encode("ascii"), int(req_nonce), req_token.encode("ascii")))

    retorno = struct.pack(f"!hh{'80s' * n}64s", GROUP_TOKEN_VALIDATION, n, *req_sas, req_gas_token.encode("ascii"))

    return retorno 
  else:
    raise ComandoNaoReconhecido(command)
  
def decode_response(command, response, args):
  if(command == 'itr'):
    _, res_id, res_nonce, res_token = struct.unpack("!h12si64s", response)
    res_id = res_id.decode("ascii").strip()
    res_token = res_token.decode("ascii")

    return f"{res_id}:{res_nonce}:{res_token}"
  elif(command == 'itv'):
    *_, status = struct.unpack("!h12si64sb", response)
    return status
  elif(command == 'gtr'):
    n = int(args[0])
    _, _, *res_sass, res_gas_token = struct.unpack(f"!hh{'80s' * n}64s", response)

    res_gas = []

    for sas in res_sass:
      res_id, res_nonce, res_token = struct.unpack("!12si64s", sas)
      res_id = res_id.decode("ascii").strip()
      res_token = res_token.decode("ascii")

      res_gas.append(f"{res_id}:{res_nonce}:{res_token}")
    
    res_gas.append(res_gas_token.decode("ascii"))

    return "+".join(res_gas)
  elif(command == 'gtv'):
    n = len(args[0].split("+")[:-1])
    *_, status = struct.unpack(f"!hh{'80s' * n}64sb", response)

    return f"{status}"
    pass
  else:
    raise ComandoNaoReconhecido(command)