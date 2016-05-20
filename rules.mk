# ----- Files ------------------------------------------------------------------

BINARY     = $(OUTPUT_DIR)/$(OUTPUT_FILE).bin
EXECUTABLE = $(OUTPUT_DIR)/$(OUTPUT_FILE).elf
MAPFILE    = $(OUTPUT_DIR)/$(OUTPUT_FILE).map

# ----- Flags ------------------------------------------------------------------

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

LDFLAGS += $(addprefix -L, $(LIB_DIRS))
LDFLAGS += -Wl,-Map=$(MAPFILE)

LIBFLAGS = $(addprefix -l, $(LIBS))

# ----- Objects ----------------------------------------------------------------

SOURCE_FILES = $(sort $(realpath $(SOURCES)))
OBJECT_FILES = $(addsuffix .o,$(basename $(SOURCE_FILES)))

OBJECTS = $(addprefix $(OBJECT_DIR),$(OBJECT_FILES))

# ----- Rules ------------------------------------------------------------------

.PHONY: all clean download

all: $(EXECUTABLE) $(BINARY)
	@echo # New line for better reading
	$(SIZE) $<
	@echo # Another new line for even better reading

clean:
	$(RMDIR) $(OBJECT_DIR)
	$(RMDIR) $(OUTPUT_DIR)

download: $(EXECUTABLE)
	$(GDB) -q -x download.gdb $<

$(EXECUTABLE): $(OBJECTS)
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	@echo $@

$(BINARY): $(EXECUTABLE)
	$(MKDIR) $(dir $@)
	$(OBJCOPY) -O binary $< $@
	@echo $@

$(OBJECT_DIR)/%.o: /%.c
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@

$(OBJECT_DIR)/%.o: /%.cpp
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@
