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
SDKDIR = ../Gecko_SDK

EXECUTABLE = $(OUTDIR)/$(NAME).elf
MAPFILE    = $(OUTDIR)/$(NAME).map

# ----- Sources ----------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

# Gecko_SDK
INCLUDES += $(SDKDIR)/cmsis/Include
INCLUDES += $(SDKDIR)/Device/SiliconLabs/EFM32ZG/Include
INCLUDES += $(SDKDIR)/emlib/inc
SOURCES += $(SDKDIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.c
SOURCES += $(SDKDIR)/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
SOURCES += $(SDKDIR)/emlib/src/em_cmu.c
SOURCES += $(SDKDIR)/emlib/src/em_gpio.c

# Project
SOURCES += src/main.cpp

# ----- Libraries --------------------------------------------------------------

LIBRARIES += stdc++
LIBRARIES += arm_cortexM0l_math

LIB_DIRS += $(SDKDIR)/cmsis/Lib/GCC

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

CFLAGS   += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++14

LDFLAGS += $(addprefix -L, $(LIB_DIRS))
LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,-Map=$(MAPFILE)
LDFLAGS += -Wl,--script=$(SDKDIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/efm32zg.ld
LDFLAGS += -Wl,--gc-sections

LIBFLAGS = $(addprefix -l, $(LIBRARIES))

include ../rules.mk
