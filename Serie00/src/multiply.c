/* gcc -Wall net.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	// unsigned 8-bit integer
	uint8_t num0;
	uint8_t num1;
	uint8_t sum;

	// argc contains executing filename
	if (argc != 3) {
		printf("Usage: <0-9> <0-9>\n");
		exit(1);
	}

	char *tmp;
	long actual0 = strtol(argv[1], &tmp, 10);
	long actual1 = strtol(argv[2], &tmp, 10);

	// catch negative numbers
	if (actual0 < 0 || actual1 < 0 ||
		actual0 > 9 || actual1 > 0) {
		printf("Usage: <0-9> <0-9>\n");
		exit(1);
	}

	num0 = (uint8_t) actual0;
	num1 = (uint8_t) actual1;
	sum = num0 * num1;

	printf("%u * %u = %u\n", num0, num1, sum);

	return 0;
}
