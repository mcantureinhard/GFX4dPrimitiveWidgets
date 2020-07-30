#ifndef PRIMITIVEOUTPUT_h
#define PRIMITIVEOUTPUT_h

#include "GFX4d.h"

class PrimitiveOutput {
    protected:
    int32_t v;
    GFX4d *gfx;
    public:
    PrimitiveOutput(GFX4d *gfx);
    virtual ~PrimitiveOutput(){}
    virtual void update(int32_t value){ v = value; }
    virtual int32_t getValue(){ return v; }
};

#endif