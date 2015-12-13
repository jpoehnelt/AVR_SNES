#ifndef SNES_H
#define SNES_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define LATCH_DDR DDRA
#define LATCH_PORT PORTA
#define LATCH_PIN (1 << 2)  // blue

#define CLOCK_DDR DDRA
#define CLOCK_PORT PORTA
#define CLOCK_PIN (1)       // yellow

#define DATA_PORT PINB
#define DATA_PIN (1)   // red

#define BUTTON_B        0
#define BUTTON_Y        1
#define BUTTON_SELECT   2
#define BUTTON_START    3
#define BUTTON_UP       4
#define BUTTON_DOWN     5
#define BUTTON_LEFT     6
#define BUTTON_RIGHT    7
#define BUTTON_A        8
#define BUTTON_X        9
#define BUTTON_L        10
#define BUTTON_R        11


void snes_init();

unsigned short snes_read();

void snes_print_state(unsigned short state);

#endif

