include ../event_lib/Makefile
TARGET=sample_cpp.$(TYPE)
CC=sh4-elf-g++
EXFLAGS=-fpermissive 

all: rm-elf $(TARGET)

$(TARGET).elf: main.cpp
	$(CC) $(CFLAGS) $(EXFLAGS) -o $@ main.cpp

$(TARGET): $(TARGET).elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) $(TARGET) $(TARGET).elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) $(TARGET).elf
