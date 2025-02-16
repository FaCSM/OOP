#include "interface.h"


const int WINDOW_SIZE_X = 400;
const int WINDOW_SIZE_Y = 440;

TInterface::TInterface(TSample *sample, QWidget *parent) : QWidget(parent) {
    setWindowTitle("#7. Graph painter");
    setFixedSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    this->sample = sample;

    btnUpdFile = new QPushButton("Change file", this);
    btnUpdFile->setGeometry(300, 405, 80, 30);
    connect(btnUpdFile, SIGNAL(pressed()), this, SLOT(updFile()));
}


TInterface::~TInterface() {
    delete btnUpdFile;
    delete sample;
}


void TInterface::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    QRect rect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y - 40);
    sample->draw(&painter, rect);
    painter.end();
}


void TInterface::updFile() {
    TParser parser;
    sample->chgSource(&parser);
    if (sample->empty()) close();
}