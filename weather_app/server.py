from http.server import HTTPServer, SimpleHTTPRequestHandler
import socketserver
import os

PORT = 8000

class Handler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=os.path.join(os.path.dirname(__file__), "templates"), **kwargs)

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"Server running at http://0.0.0.0:{PORT}")
    print(f"On your phone, use: http://192.168.1.105:{PORT}")
    httpd.serve_forever()
