# ----- CMSIS ------------------------------------------------------------------

INCLUDES += sdk/cmsis/Include
LIB_DIRS += sdk/cmsis/Lib/GCC

# ----- Device -----------------------------------------------------------------

INCLUDES += sdk/Device/SiliconLabs/EFM32ZG/Include
SOURCES += sdk/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.c
SOURCES += sdk/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
LINKERSCRIPT = sdk/Device/SiliconLabs/EFM32ZG/Source/GCC/efm32zg.ld

# ----- emdrv ------------------------------------------------------------------

INCLUDES += sdk/emdrv/common/inc

# INCLUDES += sdk/emdrv/dmadrv/inc
# SOURCES += $(wildcard sdk/emdrv/dmadrv/src/*.c)

INCLUDES += sdk/emdrv/gpiointerrupt/inc
SOURCES += $(wildcard sdk/emdrv/gpiointerrupt/src/*.c)

# INCLUDES += sdk/emdrv/nvm/inc
# SOURCES += $(wildcard sdk/emdrv/nvm/src/*.c)

# INCLUDES += sdk/emdrv/rtcdrv/inc
# SOURCES += $(wildcard sdk/emdrv/rtcdrv/src/*.c)

# INCLUDES += sdk/emdrv/sleep/inc
# SOURCES += $(wildcard sdk/emdrv/sleep/src/*.c)

# INCLUDES += sdk/emdrv/spidrv/inc
# SOURCES += $(wildcard sdk/emdrv/spidrv/src/*.c)

# INCLUDES += sdk/emdrv/tempdrv/inc
# SOURCES += $(wildcard sdk/emdrv/tempdrv/src/*.c)

# INCLUDES += sdk/emdrv/uartdrv/inc
# SOURCES += $(wildcard sdk/emdrv/uartdrv/src/*.c)

# INCLUDES += sdk/emdrv/ustimer/inc
# SOURCES += $(wildcard sdk/emdrv/ustimer/src/*.c)

# ----- emlib ------------------------------------------------------------------

INCLUDES += sdk/emlib/inc
SOURCES += $(wildcard sdk/emlib/src/*.c)

# ----- Flags ------------------------------------------------------------------

LDFLAGS += -Wl,--script=$(LINKERSCRIPT)
