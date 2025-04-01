#!/usr/bin/env python3

# HOST: pugna.snes.dcc.ufmg.br (150.164.213.243, 2804:1f4a:dcc:ff03::1) 
# PORTA: 51001

import socket
import sys

from utils import (
  valid_commands,
  encode_message,
  ipv4oripv6,
  check_for_error,
  decode_response
)

from error import (ComandoNaoReconhecido)


args = sys.argv[1:]

host, port, command = args[:3]
adrr_family, ip = ipv4oripv6(host, port)

if(command not in valid_commands()):
  raise ComandoNaoReconhecido(command)

client_socket = socket.socket(adrr_family, socket.SOCK_DGRAM)
client_socket.settimeout(5)
client_socket.connect((ip, int(port)))

req_message = encode_message(command, args[3:])

client_socket.send(req_message)

response = client_socket.recv(1024)

check_for_error(response)

print(decode_response(command, response, args[3:]))

client_socket.close()