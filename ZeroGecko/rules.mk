# ----- Directories and Files --------------------------------------------------

OBJDIR = _obj
OUTDIR = _out

BINARY     = $(OUTDIR)/$(NAME).bin
EXECUTABLE = $(OUTDIR)/$(NAME).elf
MAPFILE    = $(OUTDIR)/$(NAME).map

# ----- Flags ------------------------------------------------------------------

CPPFLAGS += $(addprefix -D, $(SYMBOLS))
CPPFLAGS += $(addprefix -I, $(INCLUDES))

LDFLAGS += -Wl,-Map=$(MAPFILE)
LDFLAGS += $(addprefix -L, $(LIB_DIRS))

LIBFLAGS = $(addprefix -l, $(LIBRARIES))

# ----- Objects ----------------------------------------------------------------

vpath %.c $(dir $(filter %.c,$(SOURCES)))
vpath %.cpp $(dir $(filter %.cpp,$(SOURCES)))

OBJECTS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))

# ----- Implicit rules ------------------------------------------------------------

.PHONY: all clean size

.PRECIOUS: $(OBJECTS)

.SILENT:

# ----- Phony rules ------------------------------------------------------------

all: $(BINARY)

clean:
	$(RM) $(OUTDIR) $(OBJDIR)

download: $(EXECUTABLE)
	$(GDB) -x download.gdb $<

size: $(EXECUTABLE)
	$(SIZE) $^

# ----- Output Files -----------------------------------------------------------

$(BINARY): $(EXECUTABLE) | $(OUTDIR)
	$(OBJCOPY) -O binary $< $@
	echo $@

$(EXECUTABLE): $(OBJECTS) | $(OUTDIR)
	$(GCC) $(GCCFLAGS) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	echo $@
	
$(OBJDIR) $(OUTDIR):
	$(MKDIR) $@

# ----- Pattern rules ----------------------------------------------------------

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	echo $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	echo $@

$(OBJDIR)/%.o: %.s | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(ASLAGS) -c -o $@ $<
	echo $@

$(OBJDIR)/%.o: %.S | $(OBJDIR)
	$(GCC) $(GCCFLAGS) $(ASLAGS) -x assembler-with-cpp $(CPPFLAGS) -c -o $@ $<
	echo $@
