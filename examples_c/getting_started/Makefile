CFLAGS = -g
LDLIBS = -ldb

header  = gettingstarted_common.h
sources = example_database_load.c \
	  example_database_read.c \
	  gettingstarted_common.c
objects = $(patsubst %.c, %.o, $(sources))
programs = load read

.PHONY: all
all: $(programs)

load: example_database_load.o gettingstarted_common.o
	$(LINK.o) $^ $(LDLIBS) -o $@
read: example_database_read.o gettingstarted_common.o
	$(LINK.o) $^ $(LDLIBS) -o $@
%.o: %.c %.h
	$(COMPILE.c) $< -o $@
%.o: %.c
	$(COMPILE.c) $< -o $@


.PHONY: clean
clean:
	$(RM) $(programs) $(objects) *.db
