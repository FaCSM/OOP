#ifndef OOP_SAMPLE_H
#define OOP_SAMPLE_H


#include "parser.h"

#include <QPainter>
#include <map>


class TSample {
private:
    Graph *graph;

public:
    TSample(TParser*);
    void chgSource(TParser *parser);

    bool empty();
    void draw(QPainter*, QRect&);
};


#endif
