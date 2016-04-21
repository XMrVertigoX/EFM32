# ----- Toolchain --------------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-

GCC     = $(TOOLCHAIN_PREFIX)gcc
GDB     = $(TOOLCHAIN_PREFIX)gdb
SIZE    = $(TOOLCHAIN_PREFIX)size

# ----- Tools ------------------------------------------------------------------

MKDIR = mkdir -p
RMDIR = rm -rf

# ----- Sources ----------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

include sdk.mk

INCLUDES += freertos/include
INCLUDES += freertos/portable/GCC/ARM_CM0
SOURCES += $(wildcard freertos/*.c)
SOURCES += freertos/portable/MemMang/heap_3.c
SOURCES += freertos/portable/GCC/ARM_CM0/port.c

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

CFLAGS   += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++14

LDFLAGS += -Wl,--gc-sections
LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs

# ----- Directories and Files --------------------------------------------------

NAME = firmware

OBJDIR = _obj
OUTDIR = _out
SRCDIR = src

EXECUTABLE = $(OUTDIR)/$(NAME).elf
MAPFILE    = $(OUTDIR)/$(NAME).map

# ----- Flags ------------------------------------------------------------------

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

LDFLAGS += -Wl,-Map=$(MAPFILE)
LDFLAGS += $(addprefix -L, $(LIB_DIRS))

LIBFLAGS = $(addprefix -l, $(LIBRARIES))

# ----- Objects ----------------------------------------------------------------

OBJECTS = $(addprefix $(OBJDIR)/,$(addsuffix .o,$(basename $(SOURCES))))

# ----- Rules ------------------------------------------------------------------

.PHONY: all clean download size

.PRECIOUS: $(OBJECTS)

.SILENT:

all: $(EXECUTABLE)

clean:
	$(RMDIR) $(OUTDIR) $(OBJDIR)

download: $(EXECUTABLE)
	$(GDB) -x download.gdb $<

size: $(EXECUTABLE)
	$(SIZE) $^

$(OBJDIR) $(OUTDIR):
	$(MKDIR) $@

$(EXECUTABLE): $(OBJECTS) | $(OUTDIR)
	$(GCC) $(GCCFLAGS) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	echo $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	echo $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	echo $@
