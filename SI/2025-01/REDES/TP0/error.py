# Definição dos códigos de erro
ERROR_CODES = {
    1: "INVALID_MESSAGE_CODE: Unknown request type",
    2: "INCORRECT_MESSAGE_LENGTH: Request size is incompatible",
    3: "INVALID_PARAMETER: Invalid field in request",
    4: "INVALID_SINGLE_TOKEN: Invalid SAS in GAS",
    5: "ASCII_DECODE_ERROR: Non-ASCII character detected"
}

class ServerError(Exception):
    """ Exceção personalizada para erros enviados pelo servidor. """
    def __init__(self, error_code):
        self.error_code = error_code
        self.message = ERROR_CODES.get(error_code, "UNKNOWN_ERROR: Unrecognized error code")
        super().__init__(f"Server Error {error_code}: {self.message}")

class ComandoNaoReconhecido(Exception):
    def __init__(self, command):
        self.command = command
        self.message = f"Comando não reconhecido {self.command}"
        super().__init__(f"Server Error: {self.message}")

class HostInvalido(Exception):
    def __init__(self, host: str, port: int):
        super().__init__(f"Unable to connect to the host: {host}:{port}.")