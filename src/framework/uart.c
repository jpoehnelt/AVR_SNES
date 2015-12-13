/*
 * Code provided by Ryan Middleton
 * CS499 Embedded Systems
 */

#include "uart.h"

void uart_init() {
    //These are the 2 lines of "magic" to enable stdio functions to work over UART
    static FILE uart_stream = FDEV_SETUP_STREAM(uart_tx, uart_rx, _FDEV_SETUP_RW);
    stdout = stdin = &uart_stream;

    //Put baud rate into baud rate register
    UBRR0H = (BAUD_FREQ >> 8);
    UBRR0L = BAUD_FREQ;

    //Configure the receiver and transmitter to be enabled and to use 8-bit
    //byte format
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
}

//Transmit a char over UART
void uart_tx(char data) {
    while (!(UCSR0A & (1 << UDRE0))); //Wait for previous transmission to finish
    UDR0 = data;
}

//Receive a char over UART
char uart_rx() {
    while (!(UCSR0A & (1 << RXC0))); //Wait until a full char has been received
    return UDR0;
}

//Read up to max_len bytes from UART into buffer. Stop if receive \r or \n and
//echo back every received byte so that it will display in the terminal window
void scanUART(char *buffer, int max_len) {
    int i;
    for (i = 0; i < max_len; i++) {
        buffer[i] = uart_rx();    //receive next byte
        uart_tx(buffer[i]);          //echo back byte
        if (buffer[i] == '\n' || buffer[i] == '\r') {
            break;//stop receiving if user pressed enter
        }
    }
    buffer[i] = '\0';  //overwrite last (usually new line char) with null-terminating char

}

//Print a string (with len chars) over UART
void printUART(char *str, int len) {
    int i = 0;
    for (i = 0; i < len; i++) uart_tx(str[i]);
}