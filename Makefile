CFLAGS = -g
LDLIBS = -ldb

sources = delemployee.c getemployee.c listemployees.c newemployee.c
headers = emp.h
programs = $(basename $(sources))

.PHONY: all
all: $(programs)

%: %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

$(programs): emp.h

.PHONY: clean
clean:
	$(RM) $(programs) *.db
