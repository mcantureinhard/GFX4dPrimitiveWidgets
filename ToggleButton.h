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
    ToggleButton(uint16_t *, int, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, String *, int, GFX4d*, void (*)(int, int, int), int, int, int);
    ~ToggleButton();
    void touched(uint16_t x, uint16_t y);
    void released();
};

#endif