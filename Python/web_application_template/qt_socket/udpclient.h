// udpclient.h
#pragma once

#include <QUdpSocket>

class UdpClient : public QUdpSocket {
    Q_OBJECT

public:
    UdpClient(QObject* parent = nullptr);

public slots:
    void readPendingDatagrams();
};
