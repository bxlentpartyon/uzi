CA := ca65
CC := cc65
LD := ld65

CC65_DIR := $(UZIBUILD_ROOT)/cc65/

PLATFORM := nes

TARGET := uzi.nes
LINKER_SCRIPT := uzi.cfg

KERNEL_FILES 	:= scall1.o scall2.o dispatch.o machdep.o process.o extras.o
DRIVER_FILES 	:= devio.o devmisc.o devtty.o #devwd.o devflop.o
FS_FILES	:= filesys.o

KERNEL_OBJECTS	:= $(patsubst %, kernel/%, $(KERNEL_FILES))
DRIVER_OBJECTS	:= $(patsubst %, drivers/%, $(DRIVER_FILES))
FS_OBJECTS	:= $(patsubst %, fs/%, $(FS_FILES))

TARGET_DEPS := $(KERNEL_OBJECTS) $(DRIVER_OBJECTS) $(FS_OBJECTS)

.PRECIOUS: %.s %.o

all: $(TARGET)

clean:
	rm -f *.o *.nes

%.o: %.c
%.s: %.c
	$(CC) --target $(PLATFORM) -I$(CC65_DIR)/include/ -I$(PWD)/include/ -O $<

%.o: %.s
	$(CA) $<

$(TARGET): $(TARGET_DEPS) $(LINKER_SCRIPT)
	$(LD) -m link.map -C $(LINKER_SCRIPT) -o $@ $(TARGET_DEPS) $(PLATFORM).lib
