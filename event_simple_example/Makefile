include ../event_lib/Makefile

all: rm-elf $(TARGET)

event.elf: main.c
	$(CC) $(CFLAGS) -o $@ main.c 

event.$(TYPE): event.elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) event.$(TYPE) event.elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) event.elf
