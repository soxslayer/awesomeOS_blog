#pragma once

#include "types.h"

#define PIN0 0
#define PIN1 0
#define PIN2 0
#define PIN3 0
#define PIN4 0
#define PIN5 0
#define PIN6 0
#define PIN7 0
#define PIN8 0
#define PIN9 0
#define PIN10 0
#define PIN11 0
#define PIN12 0
#define PIN13 0
#define PIN14 0
#define PIN15 0
#define PIN16 0
#define PIN17 0
#define PIN18 0
#define PIN19 0
#define PIN20 0
#define PIN21 0
#define PIN22 0
#define PIN23 0
#define PIN24 0
#define PIN25 0
#define PIN26 0
#define PIN27 0
#define PIN28 0
#define PIN29 0
#define PIN30 0
#define PIN31 0

struct gpio
{
  volatile uint32_t *clk_ctrl;
  uint32_t base;
};

extern struct gpio gpio0;
extern struct gpio gpio1;
extern struct gpio gpio2;
extern struct gpio gpio3;

void gpio_init(struct gpio *dev);
void gpio_enable_output(struct gpio *dev, int8_t pin);
void gpio_pin_high(struct gpio *dev, uint8_t pin);
void gpio_pin_low(struct gpio *dev, uint8_t pin);
void gpio_mask_high(struct gpio *dev, uint32_t mask);
void gpio_mask_low(struct gpio *dev, uint32_t mask);
