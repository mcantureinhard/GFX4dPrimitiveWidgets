#include "PWButton.h"

PWButton::PWButton(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String text, GFX4d *gfx, void (*callback)(int, int, int), int textsize, int id)
: PrimitiveInput{colorb, colorbp, tcolor, x, y, w, h, gfx, callback, id}
{
    this->text = text;
    this->textsize = textsize;
    drawButton();
    
}

PWButton::~PWButton(){
    return;
}

void PWButton::updateText(String  text) {
    this->text = text;
}

void PWButton::drawButton(){
    uint16_t color;
    if(state == RELEASED){
        color = colorb;
    } else {
        color = colorbp;
    }
    gfx->RoundRectFilled(x+2, y+2, x + w - 2, y + h - 2, 2,color);
    int8_t tfont = 1;
    int8_t textsizeht = textsize;
    int8_t tfw;
    int8_t tfh;
    if(tfont < 2){
        tfw = 6;
        tfh = 8;
    } else {
        tfw = 9;
        tfh = 16;
    }
    gfx->TextColor(tcolor, tcolor);
    gfx->Font(tfont);
    uint8_t blen = text.length();
    if(blen > 0){
        gfx->TextSize(textsize);
        gfx->MoveTo(((x + (w / 2) - ((blen * tfw * textsize) / 2))), ((y + (h / 2) - ((tfh * textsizeht)/ 2)) + 1));
        gfx->print(text);
    }
}

void PWButton::touched(uint16_t x, uint16_t y){
    if(!enabled){
        return;
    }
    if(state != PRESSED){
        state = PRESSED;
        drawButton();
        callback(PRESSED, id, 0);
    }
}

void PWButton::released(){
    if(!enabled){
        return;
    }
    if(state != RELEASED){
        state = RELEASED;
        drawButton();
        callback(RELEASED, id, 0);
    }
}

void PWButton::setEnabled(bool enabled){
    if(this->enabled == enabled){
        return;
    }
    this->enabled = enabled;
    if(enabled){
        colorb = bgSave;
    } else {
        bgSave = colorb;
        colorb = DARKGRAY;
        state = RELEASED;
    }
    drawButton();
}