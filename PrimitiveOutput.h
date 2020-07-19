#ifndef PRIMITIVEOUTPUT_h
#define PRIMITIVEOUTPUT_h

#include "GFX4d.h"

class PrimitiveOutput {
    public:
    virtual ~PrimitiveOutput(){}
    virtual void update(int32_t value){}
};

#endif