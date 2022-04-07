
#include "gpio.h"
#define UART ((NRF_UART_REG*)0x40002000)
typedef struct {

    volatile uint32_t STARTRX;
    volatile uint32_t STOPRX;
    volatile uint32_t STARTTX;
    volatile uint32_t STOPTX[4];
    volatile uint32_t SUSPEND[57];
    volatile uint32_t CTS;
    volatile uint32_t NCTS;
    volatile uint32_t RXDRDY[5];
    volatile uint32_t TXDRDY[2];
    volatile uint32_t EROOR[8];
    volatile uint32_t RXTO[47];
    volatile uint32_t SHORTS[65];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR[94];
    volatile uint32_t ERRORSRC[32];
    volatile uint32_t ENABLE[2];
    volatile uint32_t PSEL_RTS;
    volatile uint32_t PSEL_TXD;
    volatile uint32_t PSEL_CTS;
    volatile uint32_t PSEL_RXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED; 
    volatile uint32_t BAUDRATE[18];
    volatile uint32_t CONFIG;
} NRF_UART_REG;

//mangler 64 ett eller annet sted
void uart_init();
void uart_send(char letter);
char uart_read();

