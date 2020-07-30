#include "PrimitiveInput.h"

PrimitiveInput::PrimitiveInput(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int,int), int id){
    this->colorb = colorb;
    this->colorbp = colorbp;
    this->tcolor = tcolor;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->gfx = gfx;
    this->callback = callback;
    this->id = id;
    enabled = true;
}

void PrimitiveInput::setEnabled(bool enabled){
    this->enabled = enabled;
}