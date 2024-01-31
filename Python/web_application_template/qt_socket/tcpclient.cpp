// tcpclient.cpp
#include "tcpclient.h"
#include <QDataStream>

TcpClient::TcpClient(QObject* parent)
    : QTcpSocket(parent) {
    connect(this, &QTcpSocket::readyRead, this, &TcpClient::readData);
}

void TcpClient::readData() {
    QByteArray data = readAll();
    
    // Assume the data received is a QString
    QString receivedString;
    QDataStream stream(&data, QIODevice::ReadOnly);
    stream >> receivedString;

    // Process received string
    qDebug() << "Received: " << receivedString;
}
