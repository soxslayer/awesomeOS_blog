#include "gpio.h"

#define USR_LED0 21
#define USR_LED1 22
#define USR_LED2 23
#define USR_LED3 24

void main()
{
  gpio_init(&gpio1);

  gpio_enable_output(&gpio1, USR_LED0);
  gpio_pin_high(&gpio1, USR_LED0);

  while (1);
}
