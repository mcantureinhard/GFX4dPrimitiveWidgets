#include "ToggleButton.h"

ToggleButton::ToggleButton(uint16_t *colorb, int colors, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String *textOptions, int options, GFX4d *gfx, void (*callback)(int, int, int), int textsize, int id, int selected=0)
: PWButton{colorb[selected%colors], colorbp, tcolor, x, y, w, h, textOptions[selected], gfx, callback, textsize, id}
{
    this->textOptions = textOptions;
    this->options = options;
    this->colorsb = colorb;
    this->colors = colors;
    this->selected = selected;
    selectedColor = selected%colors;
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
        updateText(textOptions[selected]);
        drawButton();
        callback(state, id, selected);
    }
}

void ToggleButton::released(){
    if(!enabled){
        return;
    }
    if(state != RELEASED){
        state = RELEASED;
        drawButton();
        callback(state, id, selected);
    }
}