CA := ca65
CC := cc65
LD := ld65

CC65_DIR := $(UZIBUILD_ROOT)/cc65/

PLATFORM := uzi

TARGET := uzi.nes
LINKER_SCRIPT := uzi.cfg

KERNEL_FILES 	:= scall1.o scall2.o dispatch.o machdep.o process.o extras.o kdata.o
DRIVER_FILES 	:= devio.o devmisc.o devtty.o #devwd.o devflop.o
FS_FILES	:= filesys.o
LIB_FILES	:= neschar.o

KERNEL_OBJECTS	:= $(patsubst %, kernel/%, $(KERNEL_FILES))
DRIVER_OBJECTS	:= $(patsubst %, drivers/%, $(DRIVER_FILES))
FS_OBJECTS	:= $(patsubst %, fs/%, $(FS_FILES))
LIB_OBJECTS	:= $(patsubst %, lib/%, $(LIB_FILES))

TARGET_DEPS := $(KERNEL_OBJECTS) $(DRIVER_OBJECTS) $(FS_OBJECTS) $(LIB_OBJECTS) header.o

.PRECIOUS: %.s %.o
.SUFFIXES:

all: $(TARGET)

clean:
	rm -f */*.s */*.o *.o *.nes

%.s: %.c
	@echo "Building .c to .s $<"
	$(CC) --target $(PLATFORM) -I$(CC65_DIR)/include/ -I$(PWD)/include/ -O $<

%.o: %.S
	@echo "Building .S $<"
	$(CA) $<

%.o: %.s
	@echo "Building .s $<"
	$(CA) $<

$(TARGET): $(TARGET_DEPS) $(LINKER_SCRIPT)
	$(LD) -v -m link.map -C $(LINKER_SCRIPT) -o $@ header.o $(KERNEL_OBJECTS) $(DRIVER_OBJECTS) $(FS_OBJECTS) $(LIB_OBJECTS) uzi.lib
