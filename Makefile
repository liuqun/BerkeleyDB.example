CFLAGS = -g
LDLIBS = -ldb

sources = delemployee.c getemployee.c listemployees.c newemployee.c
headers = employee_record.h
programs = $(basename $(sources))

.PHONY: all
all: $(programs)

%: %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

$(programs): $(headers)

.PHONY: clean
clean:
	$(RM) $(programs) *.db
