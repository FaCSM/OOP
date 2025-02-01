#include "application.h"


TApplication::TApplication(int argc, char *argv[]) : QApplication(argc, argv) {
    TCommParams pars = {
        HostIP("127.0.0.1"), 10001,
        HostIP("127.0.0.1"), 10000
    };
    comm = new TCommunicator(pars, this);

    interface = new TInterface();
    interface->show();

    connect(comm, SIGNAL(received(QByteArray)), this, SLOT(fromCommunicator(QByteArray)));
    connect(interface, SIGNAL(request(QString)), this, SLOT(toCommunicator(QString)));
}


void TApplication::fromCommunicator(QByteArray msg) {
    interface->ans(QString(msg));
}


void TApplication::toCommunicator(QString msg) {
    comm->send(QByteArray().append(msg.toStdString()));
}
