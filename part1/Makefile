SRCS:= \
  gpio.c \
  init2.c \
  init1.s \
  main.c

TARGET=awesomeOS
TARGET_ELF:=$(TARGET).elf
TARGET_ELF_STRIPPED:=$(TARGET)_strip.elf
TARGET_SREC:=$(TARGET).srec
TARGET_BIN:=$(TARGET).bin
TARGET_LIST:=$(TARGET).list

OBJS:=$(SRCS:.c=.o)
OBJS:=$(OBJS:.s=.o)

DEPS:=$(SRCS) $(INIT_SRCS)
DEPS:=$(DEPS:.c=.d)
DEPS:=$(DEPS:.s=.ds)

ARMGNU:=arm-none-eabi

CC:=$(ARMGNU)-gcc
AS:=$(ARMGNU)-as
LD:=$(ARMGNU)-ld
OBJCOPY:=$(ARMGNU)-objcopy
OBJDUMP:=$(ARMGNU)-objdump
STRIP:=$(ARMGNU)-strip

CFLAGS:= \
  -Wall \
  -Werror \
  -Wno-unused-function \
  -nostdlib \
  -nostartfiles \
  -ffreestanding \
  -mhard-float \
  -march=armv7-a \
  -g

CPPFLAGS:=-Isrc

ASFLAGS:= \
  --warn \
  --fatal-warnings \
  -mfloat-abi=hard \
  -g

MEMORY_LAYOUT=linker.ld

LDFLAGS:=-T $(MEMORY_LAYOUT)

vpath %.c src
vpath %.c src/$(ARCH)
vpath %.s src
vpath %.s src/$(ARCH)

all: $(TARGET_SREC) $(TARGET_LIST) $(TARGET_BIN) $(TARGET_ELF_STRIPPED)

$(TARGET_ELF): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

$(TARGET_ELF_STRIPPED): $(TARGET_ELF)
	$(STRIP) $(STRIP_FLAGS) -o $@ $^

$(TARGET_LIST): $(TARGET_ELF)
	$(OBJDUMP) -S -D $^ > $@

$(TARGET_SREC): $(TARGET_ELF)
	$(OBJCOPY) $^ -O srec $@

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) $^ -j .init -j .text -j .data -j .rodata -j .vector_table -O binary $@

.PHONY: clean
clean:
	rm -f $(TARGET)* *.o *.d *.ds

ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif

MAKEFILE_DEPS:=Makefile

%.d: %.c
	$(CC) $(CPPFLAGS) -M -MG $< | sed 's|\($*.o\):|\1 $@: $(MAKEFILE_DEPS)|g' > $@

%.ds: %.s
	$(CC) $(CPPFLAGS) -M -MG $< | sed 's|\($*.o\):|\1 $@: $(MAKEFILE_DEPS)|g' > $@
