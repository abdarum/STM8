SDCC=sdcc
SDLD=sdld
OBJECTS=blinky.ihx
OBJECT=blinky

.PHONY: all clean flash

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f *.rel *~ *core *.s *.asm *.cdb *.lst *.sym *.rst *.asm  \
	*.cdb *.rel *.lst *.sym *.rst *.lib *~ *.asm *.adb *.rel *.lst \
	 *.sym *.rst *.lib *~ *.lk *.map

flash: $(OBJECT).ihx
	stm8flash -c stlinkv2 -p stm8s103f3 -w $(OBJECT).ihx

%.ihx: %.c
	$(SDCC) -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $<
