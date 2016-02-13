#include "gpio.h"

#include "reg.h"
#include "bits.h"

struct gpio gpio1 = {
  .base = GPIO1_BASE,
  .clk_ctrl = &CM_PER_GPIO1_CLKCTRL
};

void gpio_init(struct gpio *dev)
{
  // TRM 8.1.12.1.29
  *dev->clk_ctrl = _b(18) | _b(1);

  set_bit(GPIO_SYSCONFIG(dev->base), SOFTRESET);
  while_bits_clr(GPIO_SYSSTATUS(dev->base), _b(RESETDONE));
}

void gpio_enable_output(struct gpio *dev, int8_t pin)
{
  clr_bit(GPIO_OE(dev->base), pin);
}

void gpio_pin_high(struct gpio *dev, uint8_t pin)
{
  gpio_mask_high(dev, _b(pin));
}

void gpio_pin_low(struct gpio *dev, uint8_t pin)
{
  gpio_mask_low(dev, _b(pin));
}

void gpio_mask_high(struct gpio *dev, uint32_t mask)
{
  GPIO_SETDATAOUT(dev->base) = mask;
}

void gpio_mask_low(struct gpio *dev, uint32_t mask)
{
  GPIO_CLEARDATAOUT(dev->base) = mask;
}
