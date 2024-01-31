// tcpclient.h
#pragma once

#include <QTcpSocket>

class TcpClient : public QTcpSocket {
    Q_OBJECT

public:
    TcpClient(QObject* parent = nullptr);

public slots:
    void readData();
};
