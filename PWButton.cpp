#include "PWButton.h"

PWButton::PWButton(uint16_t colorb, uint16_t colorbp, uint16_t tcolor, uint16_t x, uint16_t y, uint16_t w, uint16_t h, String text, GFX4d *gfx, void (*callback)(int), int textsize){
    this->colorb = colorb;
    this->colorbp = colorbp;
    this->tcolor = tcolor;
    this->x = x;
    this->y = x;
    this->w = w;
    this->h = h;
    this->text = text;
    this->gfx = gfx;
    this->textsize = textsize;
    this->callback = callback;
    drawButton();
    
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
    if(state != PRESSED){
        state = PRESSED;
        drawButton();
        callback(PRESSED);
    }
}

void PWButton::released(){
    if(state != RELEASED){
        state = RELEASED;
        drawButton();
        callback(RELEASED);
    }
}