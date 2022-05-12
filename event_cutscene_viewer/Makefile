include ../event_lib/Makefile
TARGET=cutscene_viewer.$(TYPE)

all: rm-elf $(TARGET)

cutscene_viewer.elf: main.c
	$(CC) $(CFLAGS) -o $@ main.c 

cutscene_viewer.$(TYPE): cutscene_viewer.elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) cutscene_viewer.$(TYPE) cutscene_viewer.elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) cutscene_viewer.elf
