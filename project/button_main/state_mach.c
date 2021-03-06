#include <msp430.h>
#include <stdlib.h>
#include "state_mach.h"
#include "led.h"

void toggle()
{
  static char state = 0;
  
  if(state == 0) {
      red_on   = 0;
      green_on = 0;
      state    = 1;
    }
  
  else if(state == 1) {
      red_on   = 1;
      green_on = 0;
      state    = 2;
    }
  else if(state == 2) {
      red_on   = 0;
      green_on = 1;
      state    = 3;
    }
  else {
      red_on   = 1;
      green_on = 1;
      state = 0;
    }
}

void reset_state() {
  red_on   = 0;
  green_on = 0;
  led_update();
}

void led_state(unsigned char g, unsigned char r) {
  green_on    = g;
  red_on      = r;
  led_changed = 1;
  led_update();
}
