#include "ppi.h"
#include "gpiote.h"

int main()
{
    gpiote_init();
    init_PPI();

    while (1) {
        
    }

    return 0; 
}