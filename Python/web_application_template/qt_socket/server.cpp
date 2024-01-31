// server.cpp
#include "server.h"
#include "tcpclient.h"

Server::Server(QObject* parent)
    : QTcpServer(parent) {
}

void Server::incomingConnection(qintptr socketDescriptor) {
    emit newConnection(socketDescriptor);
}
