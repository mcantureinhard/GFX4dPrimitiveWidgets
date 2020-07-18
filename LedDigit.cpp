#include "LedDigit.h"

LedDigit::LedDigit(uint16_t x, uint16_t y, uint16_t colorb, uint16_t tcolor, GFX4d *gfx){
    this->gfx = gfx;
    this->x = x;
    this->y = y;
    this->colorb = colorb;
    this->tcolor = tcolor;
}

LedDigit::~LedDigit(){
}

void LedDigit::update(uint8_t value){
    uint8_t changed = segments ^ sgmMap[value];
    if(!changed){
        return;
    }

    uint8_t part_a = sgmMap[value] & 0b0000001;
    uint8_t part_b = sgmMap[value] & 0b0000010;
    uint8_t part_c = sgmMap[value] & 0b0000100;
    uint8_t part_d = sgmMap[value] & 0b0001000;
    uint8_t part_e = sgmMap[value] & 0b0010000;
    uint8_t part_f = sgmMap[value] & 0b0100000;
    uint8_t part_g = sgmMap[value] & 0b1000000;
    
    int offset = 2;
    if(changed && 0b0110110){
        int a = 7;
        int b = 34;
        for(int i = 0; i < 22; i++){
            grid[offset + a + i] = 0;
            grid[offset + b + i] = 0;
            if(part_b){
                grid[offset + a + i] |= 0x3E << 0;
            }
            if(part_c){
                grid[offset + b + i] |= 0x3E << 0;
            }
            if(part_e){
                grid[offset + b + i] |= 0x3E << 26;
            }
            if(part_f){
                grid[offset + a + i] |= 0x3E << 26;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        int a = 2;
        int b = 29;
        int c = 56;
        grid[offset + a + i] = 0;
        grid[offset + b + i] = 0;
        grid[offset + c + i] = 0;
        if(part_a){ // top h
            grid[offset + a + i] |= parts[0][i] << 0;
        }
        if(part_b){ // top r
            grid[offset + a + i] |= parts[1][i] << 0;
            grid[offset + b + i] |= parts[2][i] << 0;
        }
        if(part_c){ // bot r
            grid[offset + b + i] |= parts[1][i] << 0;
            grid[offset + c + i] |= parts[2][i] << 0;
        }
        if(part_d){ // bot h
            grid[offset + c + i] |= parts[0][i] << 0;
        }
        if(part_e){ // bot l
            grid[offset + b + i] |= parts[1][i] << 26;
            grid[offset + c + i] |= parts[2][i] << 26;
        }
        if(part_f){ // top l
            grid[offset + a + i] |= parts[1][i] << 26;
            grid[offset + b + i] |= parts[2][i] << 26;
        }
        if(part_g){ // mid h
            grid[offset + b + i] |= parts[0][i] << 0;
        }
    }

    segments = sgmMap[value];
    gfx->UserCharacter(grid, 66, x, y, tcolor, colorb);
}