from socket import *

# Message to be sent
msg = "\r\nI love computer networks!"
endmsg = "\r\n.\r\n"

# Choose a mail server (e.g., Google mail server) and call it mailserver
mailserver = "smtp.gmail.com"  # Change this to your mail server

# Specify the port for TLS/SSL (Optional Exercise 1)
port_tls = 587

# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, port_tls))  # Use port_tls for TLS/SSL

recv = clientSocket.recv(1024).decode()
print(recv)

if recv[:3] != "220":
    print("220 reply not received from server.")

# Send STARTTLS command for TLS/SSL (Optional Exercise 1)
starttlsCommand = "STARTTLS\r\n"
clientSocket.send(starttlsCommand.encode())
recv_starttls = clientSocket.recv(1024).decode()
print(recv_starttls)

# Use SSL/TLS (Optional Exercise 1)
clientSocket = ssl.wrap_socket(clientSocket, ssl_version=ssl.PROTOCOL_SSLv23)

# Send HELO command and print server response
heloCommand = "EHLO Alice\r\n"  # Use EHLO instead of HELO
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024).decode()
print(recv1)

if recv1[:3] != "250":
    print("250 reply not received from server.")

# Send AUTH LOGIN command for Gmail authentication (Optional Exercise 1)
auth_login_command = "AUTH LOGIN\r\n"
clientSocket.send(auth_login_command.encode())
recv_auth = clientSocket.recv(1024).decode()
print(recv_auth)

# Send your Gmail email address and password (Base64 encoded) for authentication (Optional Exercise 1)
email_address = "your_email@gmail.com"  # Change this to your Gmail email address
password = "your_password"  # Change this to your Gmail password
clientSocket.send(base64.b64encode(email_address.encode()) + "\r\n".encode())
recv_email = clientSocket.recv(1024).decode()
print(recv_email)

clientSocket.send(base64.b64encode(password.encode()) + "\r\n".encode())
recv_pass = clientSocket.recv(1024).decode()
print(recv_pass)

# Send MAIL FROM command and print server response
mailFromCommand = (
    "MAIL FROM:<your_email@gmail.com>\r\n"  # Change this to your Gmail email address
)
clientSocket.send(mailFromCommand.encode())
recv2 = clientSocket.recv(1024).decode()
print(recv2)

# Send RCPT TO command and print server response
rcptToCommand = "RCPT TO:<recipient_email@example.com>\r\n"  # Change this to the recipient's email address
clientSocket.send(rcptToCommand.encode())
recv3 = clientSocket.recv(1024).decode()
print(recv3)

# Send DATA command and print server response
dataCommand = "DATA\r\n"
clientSocket.send(dataCommand.encode())
recv4 = clientSocket.recv(1024).decode()
print(recv4)

# Send message data
clientSocket.send(msg.encode())

# Message ends with a single period
clientSocket.send(endmsg.encode())
recv_msg = clientSocket.recv(1024).decode()
print(recv_msg)

# Send QUIT command and get server response
quitCommand = "QUIT\r\n"
clientSocket.send(quitCommand.encode())
recv5 = clientSocket.recv(1024).decode()
print(recv5)

clientSocket.close()
