# ----- Toolchain --------------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-

GCC  = $(TOOLCHAIN_PREFIX)gcc
GDB  = $(TOOLCHAIN_PREFIX)gdb
SIZE = $(TOOLCHAIN_PREFIX)size

# ----- Tools ------------------------------------------------------------------

MKDIR = mkdir -p
RMDIR = rm -rf

# ----- Directories and Files --------------------------------------------------

NAME = firmware

OBJDIR = _obj
OUTDIR = _out

EXECUTABLE = $(OUTDIR)/$(NAME).elf
MAPFILE    = $(OUTDIR)/$(NAME).map

# ----- Sources ----------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

include sdk.mk

INCLUDES += ../FreeRTOS/Source/include
INCLUDES += ../FreeRTOS/Source/portable/GCC/ARM_CM0
SOURCES += $(wildcard ../FreeRTOS/Source/*.c)
SOURCES += ../FreeRTOS/Source/portable/MemMang/heap_3.c
SOURCES += ../FreeRTOS/Source/portable/GCC/ARM_CM0/port.c

# Global header files
INCLUDES += src/include

# Project sources files
SOURCES += $(wildcard src/*.cpp)

# ----- Libraries --------------------------------------------------------------

LIBRARIES += stdc++
LIBRARIES += arm_cortexM0l_math

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

CFLAGS   += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++17

LDFLAGS += $(addprefix -L, $(LIB_DIRS))
LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,-Map=$(MAPFILE)

LIBFLAGS = $(addprefix -l, $(LIBRARIES))

# ----- Rules ------------------------------------------------------------------

include ../rules.mk
