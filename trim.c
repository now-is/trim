/* trim left and right whitespace from first argument */

#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {
	if (argc < 2) exit(0);

	int j = 1;

	/* advance argv[1] to first non-whitespace character */
    while (*argv[1] && j) {
		switch (*argv[1]) {
		case ' ':  case '\r': case '\n':
		case '\t': case '\f': case '\v':
			argv[1]++; break;
		default:
			j = 0;
		}
	}

    if (!*argv[1]) exit(0);

	/* postion of last seen non-whitespace character */
	int k = 0;

	j = 1;
    while (argv[1][j]) {
		switch (argv[1][j]) {
			case ' ':  case '\r': case '\n':
			case '\t': case '\f': case '\v':
				break;
			default:
				k = j;
		}
		j++;
	}

	write(1, argv[1], k+1);
}
