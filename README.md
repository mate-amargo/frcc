# frcc
Fischer Random Chess Calculator

Compile:
-------
There's a Makefile just for that purpose, simply run:

make

Instalation:
-----------
Sorry, no install commands or scripts. Just have fun, if you like it, install it by hand :)

Running the program:
--------------------
Running the program with an invalid set of arguments will produce the following help:

Usage: frcc [NUMBER/POSITION]

    frcc  NUMBER

    NUMBER of the Fischer Random Chess position (0 to 959 inclusive).

    The output shows the position of the major white pieces

    on the first rank, from the "a" file to the "h" file.

    frcc POSITION

    POSITION string for which it is desired to find out

    the Fischer Random number. For example: RNBQKBNR

    frcc

    With no arguments it returns a random position string.
