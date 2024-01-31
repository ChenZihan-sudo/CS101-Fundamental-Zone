// udpserver.cpp
#include "udpserver.h"

UdpServer::UdpServer(QObject* parent)
    : QUdpSocket(parent) {
    bind(QHostAddress::Any, 1234);
    connect(this, &QUdpSocket::readyRead, this, &UdpServer::readPendingDatagrams);
}

void UdpServer::readPendingDatagrams() {
    while (hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(pendingDatagramSize());
        readDatagram(datagram.data(), datagram.size());
        // Process received data
    }
}
