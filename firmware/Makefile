SOURCES = src
HEADERS = src
OUT = build

export OBJ
OBJ += $(OUT)/main.o
OBJ += $(OUT)/timer.o
OBJ += $(OUT)/shift.o
OBJ += $(OUT)/button.o

CC = msp430-gcc
CFLAGS = -g -mmcu=msp430g2553
INCFLAGS = -I/usr/local/include -I$(HEADERS)

help:
	@echo "Targets: clean, build, flash, all" 

all: clean build flash

clean:
	@echo "Clean"
	rm -rf build

build-dir:
	mkdir -p build

flash: $(OUT)/firmware.elf
	@echo "Flashing";\
	mspdebug rf2500 "prog $(OUT)/firmware.elf"

build: $(OUT)/firmware.elf
	@echo "SUCCESSFUL";\

$(OUT)/firmware.elf: | build-dir $(OBJ)
	@echo "Link firmware";\
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(OUT)/firmware.elf

$(OUT)/main.o: $(SOURCES)/main.c $(HEADERS)/*.h
	@echo "Compile $<";\
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SOURCES)/main.c -o $(OUT)/main.o

$(OUT)/shift.o: $(SOURCES)/shift.c $(HEADERS)/shift.h
	@echo "Compile $<";\
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SOURCES)/shift.c -o $(OUT)/shift.o

$(OUT)/button.o: $(SOURCES)/button.c $(HEADERS)/button.h
	@echo "Compile $<";\
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SOURCES)/button.c -o $(OUT)/button.o

$(OUT)/timer.o: $(SOURCES)/timer.c $(HEADERS)/timer.h
	@echo "Compile $<";\
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SOURCES)/timer.c -o $(OUT)/timer.o
	
.SILENT: clean build-dir
.PHONY: clean build-dir flash build
