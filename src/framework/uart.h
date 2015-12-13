/*
 * Code provided by Ryan Middleton
 * CS499 Embedded Systems
 */

#ifndef FRAMEWORK_UART_H
#define FRAMEWORK_UART_H

#include <stdio.h>

#ifndef F_CPU
#error F_CPU must be defined
#else
#define BAUD_FREQ ((F_CPU + BAUD * 8L) / (BAUD * 16L) - 1)
#endif

#ifndef BAUD
#define BAUD  4800
#endif

#ifndef   _AVR_IO_H_
#include  <avr/io.h>

#endif

void uart_init();

void uart_tx(char);

char uart_rx();

void scanUART(char *buffer, int max_len);

void printUART(char *str, int len);

#endif //FRAMEWORK_UART_H
