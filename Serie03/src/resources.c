/* gcc -Wall -pthread ./resources.c -o resources */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_RESOURCES 5


int available_resources = MAX_RESOURCES;
int times = 100000;
pthread_mutex_t *mutex;


/* decrease available_resources by count resources
 * return 0 if sufficient resources available,
 * otherwise return -1 */
int decrease_count(int count) {
	/* TODO: Adjust to omit race condition */
	pthread_mutex_lock(mutex);
	if (available_resources < count) {
		pthread_mutex_unlock(mutex);
		return -1;
	} else {
		available_resources -= count;
		printf("Locked %i resources, now available: %i\n" , count , available_resources);
		pthread_mutex_unlock(mutex);
		return 0;
	}
}

/* increase available resources by count */
int increase_count(int count) {
	/* TODO: Adjust to omit race condition */
	pthread_mutex_lock(mutex);
	if (count + available_resources > 5) {
		pthread_mutex_unlock(mutex);
		return -1;
	} else {
		available_resources += count;
		printf("Freed %i resources, now available: %i\n" , count , available_resources);
		pthread_mutex_unlock(mutex);
		return 0;
	}
}

void *runTimes(void *null) {
	int i = 0 , result;
	while (i < times) {
		result = -1;
		while (result < 0) {result = decrease_count(1);}
		result = -1;
		while (result < 0) {result = increase_count(1);}
		i += 1;
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread0 , thread1;

	decrease_count(2);

	/* TODO: Create 2 threads that call runTimes and wait for their completion
	 * This should generate false final count of resources every now and then
	 * when run WITHOUT mutex or semaphore. */

	pthread_create(&thread0, NULL, runTimes, NULL);
	pthread_create(&thread1, NULL, runTimes, NULL);

	printf("Currently available resources (should be 3): %i\n" , available_resources);

	return 0;
}
