#include <stdio.h>
#include "main.h"

int main() {
	double start_time = 0.0;
	double end_time = 10.0;
	double step = 0.5;

	double radioactivity[MAX_N];
	double time[MAX_N];

	size_t N = experiment(radioactivity, time, start_time, end_time, step);
	add_noise(radioactivity, N);

	print_experiment_data(radioactivity, time, N);

	return 0;
}
