# Shenmue Event Script (for Dreamcast) Sample Makefile

# `make TYPE=EV1` will produce code compliant with EV1
# `make TYPE=EV2` will produce code compliant with EV2
# `make TYPE=EV3` will produce code compliant with EV3
# `make TYPE=MAIN` will compile the code similarly to 1ST_READ.BIN
# `make TYPE=PHYS` will compile the code similarly to 1ST_READ.BIN (using 0x0c010000 (physical addr for 0x8c010000) as VMA)
TYPE=EV1

PHYS    := 0x0c010000
MAIN    := 0x8c010000

EV1_VMA := 0x0c328000
EV2_VMA := 0x0c338000
EV3_VMA := 0x0c348000

VMA     := $(EV3_VMA)

ifeq ($(TYPE), EV3)
        VMA := $(EV3_VMA)
else ifeq ($(TYPE), EV2)
        VMA := $(EV2_VMA)
else ifeq ($(TYPE), EV1)
        VMA := $(EV1_VMA)
else ifeq ($(TYPE), MAIN)
        VMA := $(MAIN)
else
        VMA := $(TYPE)
endif

CC=sh4-elf-gcc -ml -m4
OBJCOPY=sh4-elf-objcopy --adjust-vma=$(VMA) -O binary -R .stack
TARGET=event.$(TYPE)

all: rm-elf $(TARGET)

event.elf: main.c
	$(CC) -T ../linker.x -o $@ main.c -nostartfiles -nostdlib -Wno-builtin-declaration-mismatch -fpic -Ttext=$(VMA) -Wa,-I./ -I/usr/include/

event.$(TYPE): event.elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) event.$(TYPE) event.elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) event.elf
