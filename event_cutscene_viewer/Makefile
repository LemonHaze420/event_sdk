include ../event_lib/Makefile
TARGET=0517.$(TYPE)
#CC=sh4-elf-g++

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
