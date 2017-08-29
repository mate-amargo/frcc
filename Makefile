CC := gcc

CFLAGS := -O2 -lm

frcc : main.c
	$(CC) $(CFLAGS) main.c -o frcc

.PHONY : clean

clean:
	$(RM) frcc
