#include <msp430.h>
#include "led.h"
#include "state_mach.h"
#include "switches.h"

unsigned char red_on      = 0;
unsigned char green_on    = 0;
unsigned char led_changed = 0;
unsigned char dim_on      = 0;
static char red_v[] = {0, LED_RED}, green_v[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_changed          = 1;
  dim_on               = 1;
  led_update();
}

void led_update()
{
  if (switch_state_changed | led_changed | dim_on) {
    
    char ledFlags = green_v[green_on] | red_v[red_on];

    P1OUT &= (0xff^LEDS) | ledFlags; 
    P1OUT |= ledFlags;               
  }
  switch_state_changed = 0;
  led_changed          = 0;
  dim_on               = 0;
}
