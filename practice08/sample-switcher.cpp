#include "sample-switcher.h"


TSampleSwitcher::TSampleSwitcher(TParser* parser) : TSample(parser) {
    if (empty()) return;
    activeIndex = 0;
}


void TSampleSwitcher::changeSrc(TParser* parser) {
    TSample::changeSrc(parser);
    activeIndex = 0;
}


void TSampleSwitcher::updateActive(bool isForward) {
    activeIndex = isForward ? ++activeIndex : --activeIndex + graph->size();
    activeIndex %= graph->size();
}


void TSampleSwitcher::draw(QPainter* painter, QRect& rect) {
    if (empty()) return;

    TSample::draw(painter, rect);

    int radius = 150;
    int vertR = 15;
    int angle = activeIndex * 360 / graph->size();
    double rad = qDegreesToRadians(static_cast<double>(angle));
    int dx = static_cast<int>(radius * qCos(rad));
    int dy = static_cast<int>(radius * qSin(rad));
    QPoint circlePoint = rect.center() + QPoint(dx, dy);
    painter->setBrush(Qt::red);
    painter->drawEllipse(circlePoint, vertR, vertR);

    std::vector<Vertex*> vertices = graph->getVertices();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 10, QFont::Bold));
    QRect textRect(circlePoint.x() - vertR, circlePoint.y() - vertR, 2*vertR, 2*vertR);
    painter->drawText(textRect, QChar(vertices[activeIndex]->getName()), QTextOption(Qt::AlignCenter));
}