#include "gpio.h"
#include "gpiote.h"


/*
	  GPIO0->PIN_CNF[21] = 1; //Row 1
	  GPIO0->PIN_CNF[22] = 1; //Row 2
	  GPIO0->PIN_CNF[15] = 1; //Row 3
	  GPIO0->PIN_CNF[24] = 1; //Row 4
	  GPIO0->PIN_CNF[19] = 1; //Row 5
*/

void gpiote_init()
{ 

    GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5] = 1;  //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5 

    GPIO0->OUTCLR = (1 << 28);
    GPIO0->OUTCLR = (1 << 11);
    GPIO0->OUTCLR = (1 << 31);
    GPIO1->OUTCLR = (1 << 5);
    GPIO0->OUTCLR = (1 << 30);


    GPIOTE->CONFIG[0] = 1; 
    GPIOTE->CONFIG[0] |= (BUTTON_A_PIN) << 8;
    GPIOTE->CONFIG[0] |= 2 << POL_SELECT_BIT;
    GPIOTE->CONFIG[0] |= (0 << 13);

    for (int i = 1; i < 6; i++) {
        GPIOTE->CONFIG[i] = 3;
        GPIOTE->CONFIG[i] |= 0x3 << POL_SELECT_BIT;  
        GPIOTE->CONFIG[i] |= 0x0 << PORT_SELECT_BIT;
        GPIOTE->CONFIG[i] |= 0 << INIT_VAL_BIT;
    
    }
    //set pins
    GPIOTE->CONFIG[1] |= 21 << 8;
    GPIOTE->CONFIG[2] |= 22 << 8;
    GPIOTE->CONFIG[3] |= 15 << 8;
    GPIOTE->CONFIG[4] |= 24 << 8;
    GPIOTE->CONFIG[5] |= 19 << 8;


}