CC := gcc
CFLAGS := -O2 -lm

SHELL := /bin/bash
PROGRAM := frcc

frcc : main.c
	$(CC) $(CFLAGS) main.c -o $(PROGRAM)

.PHONY : clean

clean:
	$(RM) $(PROGRAM)

.PHONY : test

test: $(PROGRAM)
	$(SHELL) test.sh
