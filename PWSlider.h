#ifndef PWSLIDER_h
#define PWSLIDER_h

#include "PrimitiveInput.h"

class PWSlider: public PrimitiveInput {
    private:
    //0 - 100
    uint8_t slider_pos;
    void drawSlider();
    void updateSlider(uint16_t posx, uint16_t color);
    public:
    PWSlider(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int), uint8_t initial_pos);
    ~PWSlider();
    void touched(uint16_t x, uint16_t y);
    void released();
};

#endif