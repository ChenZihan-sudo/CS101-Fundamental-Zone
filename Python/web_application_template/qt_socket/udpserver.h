// udpserver.h
#pragma once

#include <QUdpSocket>

class UdpServer : public QUdpSocket {
    Q_OBJECT

public:
    UdpServer(QObject* parent = nullptr);

public slots:
    void readPendingDatagrams();
};
