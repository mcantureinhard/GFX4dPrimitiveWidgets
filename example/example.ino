/*
    Manuel Cantu - GFX4dPrimitiveWidgets example file
*/

#include "GFX4d.h"
#include "ToggleButton.h"
#include "PWSlider.h"
#include "LedDigit.h"

GFX4d gfx = GFX4d();

#define btny 0
#define btnh 60
#define sldy 70
#define sldh 60
#define sld2y 140
#define sld2h 40

String options[] = {"on", "off"};
uint16_t colors[] = {GREEN,RED};

void cbtest(int val, int id){
  Serial.print("cbtest: ");
  Serial.println(val);
}

int m = 0;
int c = 0;
int d = 0;
int u = 0;
PWSlider *sldr;
PWSlider *sldrtwo;
ToggleButton *btn;
bool btnP = false;
LedDigit *mill;
LedDigit *cent;
LedDigit *dec;
LedDigit *uni;

void setup() {
  Serial.begin(115200);
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(true);
  gfx.BacklightOn(true);
  gfx.Orientation(PORTRAIT);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE); gfx.Font(2);  gfx.TextSize(1);
  gfx.touch_Set(TOUCH_ENABLE);
  
  btn = new ToggleButton(colors, sizeof(colors)/sizeof(colors[0]), DARKSLATEGRAY, WHITE, 0,btny,240,btnh, options, sizeof(options)/sizeof(options[0]), &gfx, &cbtest, 2, 1);

  sldr = new PWSlider(GREEN, RED, WHITE, 0,sldy,240,sldh, &gfx, &cbtest, 0, 2);
  sldrtwo = new PWSlider(CHOCOLATE, RED, AQUA, 0,sld2y,120,sld2h, &gfx, &cbtest, 0, 3);
  
  mill = new LedDigit(0, 190, BLACK, LIME, &gfx);
  cent = new LedDigit(33, 190, BLACK, LIME, &gfx);
  dec = new LedDigit(65, 190, BLACK, LIME, &gfx);
  uni = new LedDigit(97, 190, BLACK, LIME, &gfx);

}

void loop() {
  mill->update(m);
  cent->update(c);
  dec->update(d);
  uni->update(u);
  int touchXpos,touchYpos;
  btnP = false;
  if (gfx.touch_Update()) { // Update touch parameter values
    touchXpos = gfx.touch_GetX();
    touchYpos = gfx.touch_GetY();
    if(touchYpos >= sldy && touchYpos <= sldy + sldh){
      sldr->touched(touchXpos, touchYpos);
    } else if(touchYpos <= btnh){
      btn->touched(touchXpos, touchYpos);
      btnP = true;
    } else if(touchXpos >= 0 && touchXpos <= 120 && touchYpos >= sld2y && touchYpos <= sld2y + sld2h){
    sldrtwo->touched(touchXpos, touchYpos);
  }
  if(!btnP){
    btn->released();
  }
 }
 u++;
 if(u == 10){
  u = 0;
  d++;
  if(d == 10){
    d = 0;
    c++;
    if(c == 10){
      c = 0;
      m++;
      btn->setEnabled(c%2);
      if(m == 10){
        m = 0;
      }
    }
  }
 }
 yield();
}