#include "stm8l.h"

// 0x20 - PB5
// https://www.cnx-software.com/2015/04/13/how-to-program-stm8s-1-board-in-linux/ 
int main() {
        int d;
        // Configure pins
        PB_DDR = 0x20;
        PB_CR1 = 0x20;
        // Loop
        do {
                PB_ODR ^= 0x20;
                for(d = 0; d < 29000; d++) { }
        } while(1);
}
