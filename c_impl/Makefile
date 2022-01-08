CC ?= gcc
CFLAGS ?= -Wall -Wextra -Wpedantic

all: ReciprocalOfPalindromes

ReciprocalOfPalindromes: src/main.o
	$(CC) $(CFLAGS) -o ReciprocalOfPalindromes $^

.PHONY: clean

clean:
	rm -f src/*.o
	rm -f ReciprocalOfPalindromes
