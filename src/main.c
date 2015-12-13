#include "main.h"

int main() {

    uart_init();

    snes_init();

    while (1) {
        unsigned short state = snes_read(); // inverted from shift register, 1 for button press
        snes_print_state(state);
    }

}
