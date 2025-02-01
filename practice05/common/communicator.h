#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H


#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>


struct TCommParams {
    HostIP rHost;
    quint16 rPort;
    HostIP sHost;
    quint16 sPort;
};


class TCommunicator : public QUdpSocket {
private:
    Q_OBJECT
    bool ready;
    TCommParams params;

public:
    TCommunicator(TCommParams &, QObject *parent = nullptr);
    bool isReady();

signals:
    void received(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void receive();
};


#endif // COMMUNICATOR_H
