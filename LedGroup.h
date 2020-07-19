#ifndef LEDGROUP_h
#define LEDGROUP_h

#include "PrimitiveInput.h"
#include "LedDigit.h"

class LedGroup: public PrimitiveOutput {
    private:
    LedDigit **digits;
    int count;
    public:
    LedGroup(uint16_t x, uint16_t y, uint16_t colorb, uint16_t tcolor, int count, GFX4d *gfx);
    ~LedGroup();
    void update(int32_t value);
};

#endif