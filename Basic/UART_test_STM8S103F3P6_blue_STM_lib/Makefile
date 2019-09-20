SDCC=sdcc
SDLD=sdld
OBJECTS=blinky.ihx 
OBJECT=blinky

SDCCFLAGS=-I ./inc -I ./src -lstm8 -mstm8 --out-fmt-ihx 

.PHONY: all clean flash

all: stm8s_gpio.rel stm8s_uart1.rel main.rel join
#all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f *.rel *~ *core *.s *.asm *.cdb *.lst *.sym *.rst *.asm  \
	*.cdb *.rel *.lst *.sym *.rst *.lib *~ *.asm *.adb *.rel *.lst \
	 *.sym *.rst *.lib *~ *.lk *.map


flash: $(OBJECT).ihx
	stm8flash -c stlinkv2 -p stm8s103f3 -w $(OBJECT).ihx

stm8s_gpio.rel:
	$(SDCC) $(SDCCFLAGS) -c src/stm8s_gpio.c


stm8s_uart1.rel:
	$(SDCC) $(SDCCFLAGS) -c src/stm8s_uart1.c

main.rel:
	$(SDCC) $(SDCCFLAGS) -c blinky.c

join:
	$(SDCC) $(SDCCFLAGS) blinky.rel stm8s_gpio.rel #stm8s_uart1.rel

%.ihx: %.c
	$(SDCC) -Iinc -lstm8 -mstm8 --out-fmt-ihx  $(CFLAGS) $(LDFLAGS) $<
