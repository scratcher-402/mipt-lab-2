#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"

static double fdecay(double start_amount, double time, double decay_time) {
	return start_amount * exp(-time / decay_time);
}

static void tabulate_time(double* time, size_t N, double start_time, double step) {
	assert(time != NULL);
	assert(N <= MAX_N);

	for (size_t i = 0; i < N; i++) {
		time[i] = start_time + i * step;
	}
}

size_t experiment(double* radioactivity, double* time, double start_time, double end_time, double step) {
	const double decay_time = 6.7;
	
	assert(radioactivity != NULL);
	assert(time != NULL);
	
	size_t N = floor((end_time - start_time) / step);
	assert(N <= MAX_N);

	tabulate_time(time, N, start_time, step);

	for (size_t i = 0; i < N; i++) {
		radioactivity[i] = fdecay(1, time[i], decay_time);
	}
	
	return N;
}

static double gen_noise() {
	// Generate a random value in range [-1, 1] with precision 1e-5
	int int_noise = rand();
	double noise = 2.0*(double)int_noise / (double)RAND_MAX - 1.0;
	double noise_rounded = (double)floor(noise * 1e5) / 1e5;
	return noise_rounded;
}

void add_noise(double* radioactivity, size_t N) {
	assert(radioactivity != NULL);
	assert(N <= MAX_N);

	srand(time(NULL));

	for (size_t i = 0; i < N; i++) {
		radioactivity[i] += gen_noise() * NOISE_LEVEL;
	}
}
