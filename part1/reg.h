#pragma once

#include "types.h"

#define REG32(a,o) (*((volatile uint32_t *)((uint32_t)(a) + (o))))
#define REG32_RO(a,o) (*((volatile const uint32_t *)((uint32_t)(a) + (o))))

/* GPIO */
#define GPIO_SYSCONFIG(b) REG32(b, 0x10)
# define AUTOIDLE 0
# define SOFTRESET 1
# define ENAWAKEUP 2
# define IDLEMODE0 3
# define IDLEMODE1 4
#define GPIO_IRQSTATUS_RAW_0(b) REG32(b, 0x24)
#define GPIO_IRQSTATUS_0(b) REG32(b, 0x2c)
#define GPIO_IRQSTATUS_SET_0(b) REG32(b, 0x34)
#define GPIO_IRQSTATUS_CLR_0(b) REG32(b, 0x3c)
#define GPIO_IRQWAKEN_0(b) REG32(b, 0x44)
#define GPIO_SYSSTATUS(b) REG32_RO(b, 0x114)
# define RESETDONE 0
#define GPIO_OE(b) REG32(b, 0x134)
#define GPIO_RISINGDETECT(b) REG32(b, 0x148)
#define GPIO_CLEARDATAOUT(b) REG32(b, 0x190)
#define GPIO_SETDATAOUT(b) REG32(b, 0x194)

/* GPIO1 */
#define GPIO1_BASE 0x4804c000

/* CM_PER */
#define CM_PER_BASE 0x44e00000

#define CM_PER_GPIO1_CLKCTRL REG32(CM_PER_BASE, 0xac)
# define GPIO1_GDBCLK 18
# define MODULEMODE1 1
# define MODULEMODE0 0
