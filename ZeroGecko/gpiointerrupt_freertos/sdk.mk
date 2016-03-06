SDK = ../sdk

# ----- CMSIS ------------------------------------------------------------------

INCLUDES += $(SDK)/cmsis/Include
LIB_DIRS += $(SDK)/cmsis/Lib/GCC

# ----- Device -----------------------------------------------------------------

INCLUDES += $(SDK)/Device/SiliconLabs/EFM32ZG/Include
SOURCES += $(SDK)/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.c
SOURCES += $(SDK)/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
LINKERSCRIPT = $(SDK)/Device/SiliconLabs/EFM32ZG/Source/GCC/efm32zg.ld

# ----- emdrv ------------------------------------------------------------------

INCLUDES += $(SDK)/emdrv/common/inc

# INCLUDES += $(SDK)/emdrv/dmadrv/inc
# SOURCES += $(wildcard $(SDK)/emdrv/dmadrv/src/*.c)

INCLUDES += $(SDK)/emdrv/gpiointerrupt/inc
SOURCES += $(wildcard $(SDK)/emdrv/gpiointerrupt/src/*.c)

# INCLUDES += $(SDK)/emdrv/nvm/inc
# SOURCES += $(wildcard $(SDK)/emdrv/nvm/src/*.c)

# INCLUDES += $(SDK)/emdrv/rtcdrv/inc
# SOURCES += $(wildcard $(SDK)/emdrv/rtcdrv/src/*.c)

# INCLUDES += $(SDK)/emdrv/sleep/inc
# SOURCES += $(wildcard $(SDK)/emdrv/sleep/src/*.c)

# INCLUDES += $(SDK)/emdrv/spidrv/inc
# SOURCES += $(wildcard $(SDK)/emdrv/spidrv/src/*.c)

# INCLUDES += $(SDK)/emdrv/tempdrv/inc
# SOURCES += $(wildcard $(SDK)/emdrv/tempdrv/src/*.c)

# INCLUDES += $(SDK)/emdrv/uartdrv/inc
# SOURCES += $(wildcard $(SDK)/emdrv/uartdrv/src/*.c)

# INCLUDES += $(SDK)/emdrv/ustimer/inc
# SOURCES += $(wildcard $(SDK)/emdrv/ustimer/src/*.c)

# ----- emlib ------------------------------------------------------------------

INCLUDES += $(SDK)/emlib/inc
SOURCES += $(wildcard $(SDK)/emlib/src/*.c)

# ----- Flags ------------------------------------------------------------------

LDFLAGS += -Wl,--script=$(LINKERSCRIPT)
