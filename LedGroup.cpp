#include "LedGroup.h"

LedGroup::LedGroup(uint16_t x, uint16_t y, uint16_t colorb, uint16_t tcolor, int count, GFX4d *gfx){
    this->count = count;
    digits = new LedDigit*[count];
    for(int i = 0; i < count; ++i) {
        digits[i] = new LedDigit(x + (33 * i), y, colorb, tcolor, gfx);
        digits[i]->update(0);
    }
}

LedGroup::~LedGroup(){
    for(int i = 0; i < count; ++i) {
        delete [] digits[i];
    }
    delete [] digits;
}

void LedGroup::update(int32_t value){
    int c = this->count;
    while(c){
        digits[c-1]->update(value%10);
        value/=10;
        c--;
    }
}