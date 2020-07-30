#include "ToggleButton.h"

ToggleButton::ToggleButton(uint16_t *colorb, int colors, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String *textOptions, int options, GFX4d *gfx, void (*callback)(int, int), int textsize, int id)
: PWButton{colorb[0], colorbp, tcolor, x, y, w, h, &textOptions[0], gfx, callback, textsize, id}
{
    this->textOptions = textOptions;
    this->options = options;
    this->colorsb = colorb;
    this->colors = colors;
    selected = 0;
    selectedColor = 0;
}

ToggleButton::~ToggleButton(){
    return;
}

void ToggleButton::touched(uint16_t x, uint16_t y){
    if(!enabled){
        return;
    }
    if(state != PRESSED){
        state = PRESSED;
        selected = (selected + 1) % options;
        selectedColor = (selectedColor + 1) % colors;
        colorb = colorsb[selectedColor];
        updateText(&textOptions[selected]);
        drawButton();
    }
}

void ToggleButton::released(){
    if(!enabled){
        return;
    }
    if(state != RELEASED){
        state = RELEASED;
        drawButton();
        callback(selected, id);
    }
}