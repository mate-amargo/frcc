/*
 *  frcc - Fischer Random Chess Calculator
 *  -------------------------------------------------------
 *  Author: mate_amargo - Juan Alberto Regalado Galván
 *  https://github.com/mate-amargo/frcc
 *  -------------------------------------------------------
 *
 *  Usage:
 *  frcc [NUMBER/POSITION]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {a, b, c, d, e, f, g, h} square;
const int knight[10][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

const char *num2pos(int num);
int pos2num(char pos[8]);

int main(int argc, char **argv) {

	void help(void) {

	 	printf("Usage: %s [NUMBER/POSITION]\n\n", argv[0]);
		printf("  %s  NUMBER\n", argv[0]);
		puts("    NUMBER of the Fischer Random Chess position (0 to 959 inclusive).");
		puts("    The output shows the position of the major white pieces,");
		puts("    on the first rank from the \"a\" file to the \"h\" file.");
		printf("  %s POSITION\n", argv[0]);
		puts("    POSITION string for which it is desired to find out");
		puts("    the Fischer Random number. For example: RNBQKBNR");
		printf("  %s\n", argv[0]);
		puts("    With no arguments it returns a random position string.");

		exit(EXIT_FAILURE);
	}

	srand(time(NULL));

	/* Generate a random string if there were no arguments */
	if (argc == 1) {
		printf("%s\n", num2pos(rand() % 960));
		exit(EXIT_SUCCESS);
	}

	/* Provide help and exit on more than 1 argument*/
	if (argc != 2) help();

	/* We use strtol to parse the argument. */
	/* The first character that's not a digit is pointed by endp */
	int num; char *endp;
	num = strtol(argv[1], &endp, 10);
	if (endp == argv[1]) { /* Pointer comparision */
	/* Argument was a string => Find the position number */
		int k = 0, q = 0, b = 0, n = 0, r = 0, i;
		for (i = a; i <= h; i++)
			switch (argv[1][i]) {
				case 'K': case 'k':
					if (k) help(); else k++;
					break;
				case 'Q': case 'q':
					if (q) help(); else q++;
					break;
				case 'B': case 'b':
					if (b == 2) help(); else b++;
					break;
				case 'N': case 'n':
					if (n == 2) help(); else n++;
					break;
				case 'R': case 'r':
					if (r == 2) help(); else r++;
					break;
				default:
					help();
			}
		if (argv[1][i] != '\0') help(); /* Longer srting, error, exit. */
		num = pos2num(argv[1]);
		if (num < 0)
			help();
		else
			printf("%d\n", num);
	} else if (*endp == '\0' && num >= 0 && num <= 959) 
		/* Argument was a number => Find the position string */
		printf("%s\n", num2pos(num));
	else
		help();

	exit(EXIT_SUCCESS);

}

const char *num2pos(int num) {

	static char pos[8] = {'\0'};
	square bb[4] = { a, c, e, g };
	square wb[4] = { b, d, f, h };
	square posq, posn, i;

	/* Set the white Bishop (B) */
  pos[wb[num % 4]] = 'B';
  num /= 4;
	
	/* Set the black Bishop (B) */
	pos[bb[num % 4]] = 'B';
	num /= 4;

	/* Set the Queen (Q) */
	/* Place it on the (n+1)th free square, where n = num % 6 */
	i = a; posq = a;
	while (i <= h) {
		if ((pos[i] == '\0') && (posq++ == num % 6)) {
			pos[i] = 'Q';
			break;
		}
		i++;
	}
	num /= 6;

	/* Set the Knights (N) */
	/* First one: */
	i = a; posn = a;
	while (i <= h) {
		if ((pos[i] == '\0') && (posn++ == knight[num][0])) {
			pos[i++] = 'N';
			break;
		}
		i++;
	}
	/* Second one: */
	while (i <= h) {
		if ((pos[i] == '\0') && (posn++ == knight[num][1])) {
			pos[i] = 'N';
			break;
		}
		i++;
	}
	
	/* Set the leftmost Rook (R) */
	for (i = a; i <= h; i++)
		if (pos[i] == '\0') {
			pos[i] = 'R';
			break;
		}

	/* Set the King between the two Rooks (K) */
	for (i = a; i <= h; i++)
		if (pos[i] == '\0') {
			pos[i] = 'K';
			break;
		}

	/* Set the last piece, the rightmost Rook (R) */
	for (i = a; i <= h; i++)
		if (pos[i] == '\0') {
			pos[i] = 'R';
			break;
		}

	return pos;

}

int pos2num(char pos[8]) {

}
