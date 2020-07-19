#include "PWSlider.h"

PWSlider::PWSlider(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, GFX4d *gfx, void (*callback)(int, int), uint8_t initial_pos, int id)
: PrimitiveInput{colorb, colorbp, tcolor, x, y, w, h, gfx, callback, id}
{
    this->slider_pos = initial_pos;
    drawSlider();
}

PWSlider::~PWSlider(){}

// TODO: Add margin left/right
void PWSlider::drawSlider(){
    gfx->RoundRectFilled(x+2, y + 2, x + w - 2, y + h - 2, 2,colorb);
    updateSlider(slider_pos, tcolor);
}

void PWSlider::updateSlider(uint16_t posx, uint16_t color){
    uint8_t slider = ((w-2) * posx / 100);
    int16_t sliderL = x + slider - 2;
    if(sliderL < x + 2){
        sliderL = x + 2;
    }
    int16_t sliderR = x + slider + 6;
    if(sliderR > x + w - 2){
        sliderR = x + w - 2;
    }
    gfx->RectangleFilled(sliderL, y + 3, sliderR, y + h - 3, color);
}

void PWSlider::touched(uint16_t x, uint16_t y){
    uint8_t calc_pos = (x - this->x) * 101 / w;
    if(calc_pos < 0){
        calc_pos = 0;
    } else if(calc_pos > 100){
        calc_pos = 100;
    }
    if(calc_pos != slider_pos){
        updateSlider(slider_pos, colorb);
        slider_pos = calc_pos;
        updateSlider(slider_pos, tcolor);
        callback(slider_pos, id);
    }
}

void PWSlider::released(){
    return;
}