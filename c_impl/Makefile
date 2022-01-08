ifdef DEBUG
	EXTRA_CFLAGS = -g -O0
else
	EXTRA_CFLAGS = -DNDEBUG -O3
endif

CC ?= gcc
CFLAGS ?= -Wall -Wextra -Wpedantic ${EXTRA_CFLAGS}

all: ReciprocalOfPalindromes

ReciprocalOfPalindromes: src/main.o src/palindrome_generator.o
	$(CC) $(CFLAGS) -o ReciprocalOfPalindromes $^

.PHONY: clean

clean:
	rm -f src/*.o
	rm -f ReciprocalOfPalindromes
