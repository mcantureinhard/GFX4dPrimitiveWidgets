#ifndef PWBUTTON_h
#define PWBUTTON_h

#include "PrimitiveInput.h"

enum ButtonState {
    RELEASED=1,
    PRESSED=2
};

class PWButton: public PrimitiveInput {
    protected:
    String text;
    int textsize;
    uint16_t bgSave;
    ButtonState state = RELEASED;
    void drawButton();
    void updateText(String text);
    public:
    PWButton(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String text, GFX4d *gfx, void (*callback)(int, int), int textsize, int id);
    ~PWButton();
    void touched(uint16_t x, uint16_t y);
    void released();
    void setEnabled(bool);
};

#endif