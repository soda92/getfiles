from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer
from pathlib import Path

authorizer = DummyAuthorizer()
DATA_DIR = Path.joinpath(Path(__file__).resolve().parent, "data")
print(DATA_DIR)
# breakpoint()
authorizer.add_user("user", "12345", str(DATA_DIR), perm="elradfmwMT")

handler = FTPHandler
handler.authorizer = authorizer

server = FTPServer(("127.0.0.1", 21), handler)
server.serve_forever()
