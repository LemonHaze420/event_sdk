include ../event_lib/Makefile

all: rm-elf $(TARGET)

simple_example.elf: main.c
	$(CC) $(CFLAGS) -o $@ main.c 

simple_example.$(TYPE): event.elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) simple_example.$(TYPE) simple_example.elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) simple_example.elf
