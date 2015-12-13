#include "snes.h"

void snes_init() {
    LATCH_DDR |= LATCH_PIN;
    CLOCK_DDR |= CLOCK_PIN;
}

unsigned short snes_read() {
    CLOCK_PORT |= CLOCK_PIN; // high
    LATCH_PORT |= LATCH_PIN; // high
    _delay_ms(5);
    LATCH_PORT &= ~LATCH_PIN; // low

    unsigned short state = 0;
    int i;

    // Loop to receive 12 bits from the pad
    for (i = 0; i < 12; i++) {
        CLOCK_PORT |= CLOCK_PIN; // high
        _delay_ms(10);
        CLOCK_PORT &= ~CLOCK_PIN; // low

//        printf("%u", PINB & DATA_PIN);

        state |= (PINB & DATA_PIN) << i;
    }

    return ~state;
}

void snes_print_state(unsigned short state) {
    char button_b = 'O', button_y = 'O', button_select = '/', button_start = '/', button_up = '^', button_down = 'v', button_left = '<', button_right = '>', button_a = 'O', button_x = 'O', button_l = '_', button_r = '_';

    if (state & 1 << BUTTON_B) {
        button_b = 'X';
    }

    if (state & 1 << BUTTON_Y) {
        button_y = 'X';
    }

    if (state & 1 << BUTTON_X) {
        button_x = 'X';
    }

    if (state & 1 << BUTTON_A) {
        button_a = 'X';
    }

    if (state & 1 << BUTTON_UP) {
        button_up = 'X';
    }

    if (state & 1 << BUTTON_DOWN) {
        button_down = 'X';
    }

    if (state & 1 << BUTTON_LEFT) {
        button_left = 'X';
    }

    if (state & 1 << BUTTON_RIGHT) {
        button_right = 'X';
    }

    if (state & 1 << BUTTON_START) {
        button_start = 'X';
    }

    if (state & 1 << BUTTON_SELECT) {
        button_select = 'X';
    }

    if (state & 1 << BUTTON_L) {
        button_l = 'X';
    }

    if (state & 1 << BUTTON_R) {
        button_r = 'X';
    }

    printf("\n\n  __%c________________%c___\n /                       \\\n/   %c                %c    \\\n| %c   %c    %c  %c    %c   %c  |\n\\   %c                %c   /\n \\______________________/\n\n",
           button_l, button_r, button_up, button_x, button_left, button_right, button_select, button_start, button_y,
           button_a, button_down, button_b);
}
