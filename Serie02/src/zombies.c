/* gcc -Wall -std=gnu99 zombies.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_zombie(unsigned int wait) {
    pid_t child = fork();
    printf("Child_pid: %i", child);
    if (child > 0) {
        sleep(wait);
    } else {
        exit(0);
    }
}

int main(void)
{
	unsigned int wait = 15;
	create_zombie(wait);

	return 0;
}
