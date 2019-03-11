/* gcc -Wall -O2 fib.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int fib(int a) {
	if (a < 0) {
		printf("Illegal negative input for fibonacci input.\n");
		exit(1);
	}
	if (a == 0) return 0;
	if (a == 1) return 1;

	return fib(a-1) + fib(a-2);
}

int main(void)
{
	int fib_10 = fib(10);
	printf("fib(10) = %i", fib_10);
	return 0;
}
