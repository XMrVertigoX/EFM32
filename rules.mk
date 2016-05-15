# ----- Objects ----------------------------------------------------------------

OBJECTS = $(addprefix $(OBJDIR),$(abspath $(addsuffix .o,$(basename $(SOURCES)))))

# ----- Rules ------------------------------------------------------------------

.PHONY: all clean download

all: $(EXECUTABLE)
	@echo # New line for better reading
	$(SIZE) $^
	@echo # Another new line for even better reading

clean:
	$(RMDIR) $(OBJDIR)
	$(RMDIR) $(OUTDIR)

download: $(EXECUTABLE)
	$(GDB) -x download.gdb $<

$(EXECUTABLE): $(OBJECTS)
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	@echo $@

$(OBJDIR)/%.o: /%.c
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@

$(OBJDIR)/%.o: /%.cpp
	$(MKDIR) $(dir $@)
	$(GCC) $(GCCFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo $@
