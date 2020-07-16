#ifndef PRIMITIVEWIDGET_h
#define PRIMITIVEWIDGET_h

#include "GFX4d.h"

class PrimitiveWidget {
    protected:
    void (*callback)(int);
    GFX4d *gfx;
    uint16_t x;
    uint16_t w;
    uint16_t y;
    uint16_t h;
    uint16_t colorbp;
    uint16_t tcolor;
    uint16_t colorb;
    public:
    virtual void touched(uint16_t x, uint16_t y);
    virtual void released();
};

#endif