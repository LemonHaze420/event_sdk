include ../event_lib/Makefile
TARGET=bicycle_creator.$(TYPE)

all: rm-elf $(TARGET)

$(TARGET).elf: main.c
	$(CC) $(CFLAGS) -o $@ main.c 

$(TARGET): $(TARGET).elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) $(TARGET) $(TARGET).elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) $(TARGET).elf
