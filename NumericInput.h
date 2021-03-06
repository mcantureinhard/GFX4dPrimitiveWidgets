#ifndef NUMERICINPUT_h
#define NUMERICINPUT_h

#include "PrimitiveInput.h"
#include "PWButton.h"

#define DEC_FLAG 1
#define NEG_FLAG 2

#define DEC_POS 11
#define NEG_POS 9

const String numberStrings[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "-", "0", "."};

class NumericInput: public PrimitiveInput {
    private:
    PWButton **buttons;
    uint16_t bw;
    uint16_t bh;
    int lastTouched = -1;
    bool blockNext = false;
    uint8_t flags;
    public:
    NumericInput(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int, int, int), int textsize, int id, uint8_t flags);
    ~NumericInput();
    void touched(uint16_t x, uint16_t y);
    void released();
};

#endif