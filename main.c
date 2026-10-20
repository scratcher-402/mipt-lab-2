#include <stdio.h>
#include "main.h"

int main() {
	double start_time = 0.0;
	double end_time = 10.0;
	double step = 0.5;
	double precision = 1e-5;

	int count = scanf("%lf%lf%lf%lf", &start_time, &end_time, &step, &precision);
	if (count != 4) {
		puts("Input error!");
		return 1;
	}

	double radioactivity[MAX_N];
	double time[MAX_N];

	size_t N = experiment(radioactivity, time, start_time, end_time, step);
	add_noise(radioactivity, N);

	// print_experiment_data(radioactivity, time, N);

	double interval1, interval2;
	count = scanf("%lf%lf", &interval1, &interval2);
	if (count != 2) {
		puts("Input error");
		return 1;
	}

	double decay_time = nonlinear_equation(radioactivity, time, N, precision, interval1, interval2);
	printf("decay_time = %.5f\n", decay_time);
	double decay_rate = linear_equation(radioactivity, time, N);
	printf("decay_rate = %.5f\n", decay_rate);

	double time_difference = precision_analysis(radioactivity, time, N, interval1, interval2);
	printf("time_differences = %.5f\n", time_difference);

	return 0;
}
