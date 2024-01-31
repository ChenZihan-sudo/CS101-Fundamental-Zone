// udpserver.cpp
#include "udpserver.h"
#include <QDataStream>

UdpServer::UdpServer(QObject* parent)
    : QUdpSocket(parent) {
    bind(QHostAddress::Any, 1234);
    connect(this, &QUdpSocket::readyRead, this, &UdpServer::readPendingDatagrams);
}

void UdpServer::readPendingDatagrams() {
    while (hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        
        // Assume the data received is a QString
        QString receivedString;
        QDataStream stream(datagram);
        stream >> receivedString;

        // Process received string
        qDebug() << "Received from " << sender.toString() << ":" << senderPort << ": " << receivedString;
    }
}
