# ----- Files ------------------------------------------------------------------

EXECUTABLE = $(OUTPUT_DIR)/$(OUTPUT_FILE).elf
MAPFILE    = $(OUTPUT_DIR)/$(OUTPUT_FILE).map

# ----- Flags ------------------------------------------------------------------

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

LDFLAGS += $(addprefix -L, $(LIB_DIRS))
LDFLAGS += -Wl,-Map=$(MAPFILE)

LIBFLAGS = $(addprefix -l, $(LIBS))

# ----- Objects ----------------------------------------------------------------

OBJECTS = $(addprefix $(OBJECT_DIR),$(abspath $(addsuffix .o,$(basename $(SOURCES)))))

# ----- Rules ------------------------------------------------------------------

.PHONY: all clean download

all: $(EXECUTABLE)
	@echo # New line for better reading
	$(SIZE) $^
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

$(OBJECT_DIR)/%.o: /%.c
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@

$(OBJECT_DIR)/%.o: /%.cpp
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@
