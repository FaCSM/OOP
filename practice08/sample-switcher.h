#ifndef OOP_SAMPLE_SWITCHER_H
#define OOP_SAMPLE_SWITCHER_H


#include "sample.h"


class TSampleSwitcher : public TSample {
private:
    int activeIndex;

public:
    TSampleSwitcher(TParser*);
    void changeSrc(TParser*);
    void updateActive(bool);
    void draw(QPainter*, QRect&);
};


#endif
