/* gcc -Wall -pthread statistics.c */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>


int max;
int min;
float avg;
int len;

typedef struct struct_thdata {
    int *array;
} thdata;

void *average(void *val) {
    thdata *data = (thdata *) val;
	float sum = 0;
	for (int i = 0; i < len; i++) {
		sum += data->array[i];
	}
	avg = sum / len;
	return NULL;
}

void *minimum(void *val) {
    thdata *data = (thdata *) val;
	int local_min = INT_MAX;
	for (int i = 0; i < len; i++) {
		int curr = data->array[i];
		if (curr < local_min) {
			local_min = curr;
		}
	}
	min = local_min;
	return NULL;
}

void *maximum(void *val) {
    thdata *data = (thdata *) val;
	int local_max = INT_MIN;
	for (int i = 0; i < len; i++) {
		int curr = data->array[i];
		if (curr > local_max) {
			local_max = curr;
		}
	}
	max = local_max;
	return NULL;
}

int main(int argc, char *argv[])
{
    len = argc - 1;
	pthread_t thread0, thread1, thread2;
	thdata data1, data2, data3;

	if (len < 2) {
		printf("You have to supply at least 2 integers as arguments!\n");
		return 0;
	}

	int *array = malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
	    array[i] = (int) strtol(argv[i + 1], NULL, 10);
	}

	data1.array = array;
	data2.array = array;
	data3.array = array;

	pthread_create(&thread0, NULL, (void *) &average, (void *) &data1);
	pthread_create(&thread1, NULL, (void *) &maximum, (void *) &data2);
    pthread_create(&thread2, NULL, (void *) &minimum, (void *) &data3);

	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Average: %f\n" , avg);
	printf("Maximum: %i\n" , max);
	printf("Minimum: %i\n" , min);

	return 0;
}
