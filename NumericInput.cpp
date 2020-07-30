#include "NumericInput.h"

NumericInput::NumericInput(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int, int), int textsize, int id)
: PrimitiveInput{colorb, colorbp, tcolor, x, y, w, h, gfx, callback, id}
{
    this->bw = w/3;
    this->bh = h/4;
    buttons = new PWButton*[12]; // 0 - 11
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            int id = i*3+j + 1;
            if(id == 10){
                id = -1;
            } else if(id == 11){
                id = 0;
            } else if(id == 12){
                id = -2;
            }
            buttons[i*3+j] = new PWButton(colorb, colorbp, tcolor, x + this->bw*j, y + this->bh*i, this->bw, this->bh, numbers[i*3+j], gfx, callback, textsize, id);
        }
    }
}

NumericInput::~NumericInput(){
    for(int i = 0; i < 12; i++){
        delete buttons[i];
    }
    delete [] buttons;
}

void NumericInput::touched(uint16_t x, uint16_t y){
    // Won't check for bountries
    int i = (x - this->x)/this->bw;
    int j = (y - this->y)/this->bh;
    int touch = j*3+i;
    if(lastTouched != -1 && lastTouched != touch){
        blockNext = true;
        buttons[lastTouched]->released();
    }
    buttons[touch]->touched(x,y);
    lastTouched = touch;
}

void NumericInput::released(){
    if(lastTouched == -1){
        return;
    }
    int lt = lastTouched;
    lastTouched = -1;
    buttons[lt]->released();
}