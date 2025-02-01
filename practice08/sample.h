#ifndef OOP_SAMPLE_H
#define OOP_SAMPLE_H


#include "parser.h"

#include <QPainter>
#include <map>


class TSample {
protected:
    Graph *graph;

public:
    TSample(TParser*);
    virtual void changeSrc(TParser*);

    bool empty();
    virtual void draw(QPainter*, QRect&);
};


#endif
