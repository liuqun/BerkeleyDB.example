CFLAGS = -g
LDLIBS = -ldb

sources = delemployee.c getemployee.c listemployees.c newemployee.c
programs = $(basename $(sources))

.PHONY: all
all: $(programs)

.PHONY: clean
clean:
	$(RM) $(programs) *.db
