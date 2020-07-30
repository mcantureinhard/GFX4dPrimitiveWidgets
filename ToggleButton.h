#ifndef TOGGLEBUTTON_h
#define TOGGLEBUTTON_h

#include "PWButton.h"

class ToggleButton: public PWButton {
    private:
    uint16_t *colorsb;
    int colors;
    String *textOptions;
    int options;
    int selected;
    int selectedColor;
    public:
    ToggleButton(uint16_t *colorb, int colors, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String *textOptions, int options, GFX4d *gfx, void (*callback)(int, int), int textsize, int id);
    ~ToggleButton();
    void touched(uint16_t x, uint16_t y);
    void released();
};

#endif