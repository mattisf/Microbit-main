#include "uart.h"
void uart_init() {
    GPIO0->PIN_CNF[6] &= !0x1;
    GPIO1->PIN_CNF[8] |= 0x1;
    UART->PSEL_TXD = 0;
    UART->PSEL_RXD = 0;
    UART->PSEL_RXD |= (1<<3) | (1<<5);
    UART->PSEL_TXD |= (1<<1) | (1<<2);
    UART->BAUDRATE[0] = 0x00275000;
    UART->PSEL_RTS = (1<<31);
    UART->PSEL_CTS = (1<<31);
    UART->ENABLE[0] |= 4;
    UART->STARTRX |= 0x1;
}

void uart_send(char letter) {
    UART->STARTTX = 0x1;
    UART->TXD = (uint32_t )letter;
    while(!UART->TXDRDY[0]) {

    }
    UART->TXDRDY[0] = 0x0;
    UART->STOPTX[0] = 0x1;
    
}

char uart_read() {

    UART->STARTRX = 0x1;
    if (!UART->RXDRDY[0]) {
        UART->STOPRX =0x1;
        return '\0';
    }
    UART->RXDRDY[0] = 0x0;
    char val = (char) UART->RXD;
    UART->STOPRX =0x1;
    return val;

}

/*
 UART->STARTRX = 0x1;
    while (UART->RXTO[0] != 0x1) {
        if (UART->RXDRDY[0]) {
            UART->RXDRDY[0] = 0x0;
            char val = (char) UART->RXD;
            UART->STOPRX =0x1;
            return val;
        }
    }
    UART->STOPRX = 0x1; 
    return '\0';

*/