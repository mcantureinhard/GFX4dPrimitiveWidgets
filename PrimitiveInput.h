#ifndef PRIMITIVEINPUT_h
#define PRIMITIVEINPUT_h

#include "GFX4d.h"

class PrimitiveInput {
    protected:
    void (*callback)(int,int,int);
    GFX4d *gfx;
    uint16_t x;
    uint16_t w;
    uint16_t y;
    uint16_t h;
    uint16_t colorbp;
    uint16_t tcolor;
    uint16_t colorb;
    int id;
    bool enabled;
    public:
    PrimitiveInput(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int,int,int), int id);
    virtual ~PrimitiveInput(){}
    virtual void touched(uint16_t x, uint16_t y){}
    virtual void released(){}
    virtual void setEnabled(bool);
    virtual void reset(){}
};

#endif