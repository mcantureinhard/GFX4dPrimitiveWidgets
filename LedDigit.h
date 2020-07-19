#ifndef LEDDIGIT_h
#define LEDDIGIT_h

#include "GFX4d.h"
#include "PrimitiveOutput.h"

const uint32_t parts[3][5] = {
    { // horizontal
        0x3FFFFC0,
        0x7FFFFE0,
        0xFFFFFF0,
        0x7FFFFE0,
        0x3FFFFC0
    },
    { // top vertical
        0,
        0,
        0,
        0x4,
        0xE
    },
    { // bottom vertical
        0xE,
        0x4,
        0,
        0,
        0

    }
};

// num -> GFEDCBA
const uint8_t sgmMap[] = {
    0b0111111,
    0b0000110,
    0b1011011,
    0b1001111,
    0b1100110,
    0b1101101,
    0b1111101,
    0b0000111,
    0b1111111,
    0b1101111,
};


class LedDigit: public PrimitiveOutput {
    private:
    uint16_t x;
    uint16_t y;
    uint16_t colorb;
    uint16_t tcolor;
    uint8_t value;
    uint8_t segments = 0;
    uint32_t grid[66] = {32, 64,0};
    GFX4d *gfx;
    public:
    LedDigit(uint16_t x, uint16_t y, uint16_t colorb, uint16_t tcolor, GFX4d *gfx);
    ~LedDigit();
    void update(int32_t value);
};

#endif