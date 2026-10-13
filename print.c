#include <assert.h>
#include <stdio.h>
#include "main.h"

void print_experiment_data(const double* radioactivity, const double* time, size_t N) {
	assert(radioactivity != NULL);
	assert(time != NULL);
	
	printf("Time    |Radioactivity\n");

	for (size_t i = 0; i < 5 && i < N; i++) {
		printf("%8.5lf|%13.5lf\n", time[i], radioactivity[i]);
	}

	if (N > 5) {
		printf(" ...\n");

		for (size_t i = N-5; i < N; i++) {
			printf("%8.5lf|%13.5lf\n", time[i], radioactivity[i]);
		}
	}
}
