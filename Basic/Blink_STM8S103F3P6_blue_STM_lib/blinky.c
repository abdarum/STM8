#include "stm8s.h"
#include "stm8s_gpio.h"

// 0x20 - PB5 - LED
// Board description:
// https://tenbaht.github.io/sduino/hardware/stm8blue/
// Simple setup tutorial:
// https://www.cnx-software.com/2015/04/13/how-to-program-stm8s-1-board-in-linux/ 

#define LED_GPIO_PORT  (GPIOB)
#define LED_GPIO_PINS  (GPIO_PIN_5)

int main() {
        int d;

	/* Initialize I/Os in Output Mode */
	GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);

        // Loop
        do {
		/* Toggles LEDs */
		GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS);
		// d < 29000
                for(d = 0; d < 9000; d++) { }
        } while(1);
}
