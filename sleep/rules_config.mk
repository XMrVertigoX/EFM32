# ----- Toolchain -------------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-

GCC     = $(TOOLCHAIN_PREFIX)gcc
GDB     = $(TOOLCHAIN_PREFIX)gdb
OBJCOPY = $(TOOLCHAIN_PREFIX)objcopy
SIZE    = $(TOOLCHAIN_PREFIX)size

# ----- Tools -----------------------------------------------------------------

MKDIR = mkdir -p
RM = rm -rf

# ----- Directories and files -------------------------------------------------

BINARY     = $(PROJECT_NAME).bin
EXECUTABLE = $(PROJECT_NAME).elf
MAPFILE    = $(PROJECT_NAME).map

OUTPUT_DIR = _out
PARENT_DIR = $(dir $(CURDIR))

VPATH += $(OUTPUT_DIR)
