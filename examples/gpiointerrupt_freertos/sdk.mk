SDK_DIR = ../../Gecko_SDK

# ----- CMSIS ------------------------------------------------------------------

INCLUDES += $(SDK_DIR)/cmsis/Include
LIB_DIRS += $(SDK_DIR)/cmsis/Lib/GCC

# ----- Device -----------------------------------------------------------------

INCLUDES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Include
SOURCES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.c
SOURCES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
LINKERSCRIPT = $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/efm32zg.ld

# ----- emdrv ------------------------------------------------------------------

INCLUDES += $(SDK_DIR)/emdrv/common/inc

# INCLUDES += $(SDK_DIR)/emdrv/dmadrv/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/dmadrv/src/*.c)

INCLUDES += $(SDK_DIR)/emdrv/gpiointerrupt/inc
SOURCES += $(wildcard $(SDK_DIR)/emdrv/gpiointerrupt/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/nvm/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/nvm/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/rtcdrv/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/rtcdrv/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/sleep/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/sleep/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/spidrv/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/spidrv/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/tempdrv/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/tempdrv/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/uartdrv/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/uartdrv/src/*.c)

# INCLUDES += $(SDK_DIR)/emdrv/ustimer/inc
# SOURCES += $(wildcard $(SDK_DIR)/emdrv/ustimer/src/*.c)

# ----- emlib ------------------------------------------------------------------

INCLUDES += $(SDK_DIR)/emlib/inc
SOURCES += $(wildcard $(SDK_DIR)/emlib/src/*.c)

# ----- Flags ------------------------------------------------------------------

LDFLAGS += -Wl,--script=$(LINKERSCRIPT)
