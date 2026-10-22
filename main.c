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

	if (start_time > end_time) {
		printf("Invalid time interval: start_time %lf is larger than end_time %lf\n", start_time, end_time);
		return 2;
	}

	if (step <= 0) {
		printf("Invalid step %lf, it can't be negative", step);
		return 2;
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

	if (interval1 > interval2) {
		printf("Invalid interval: begin %lf is larger than end %lf\n", interval1, interval2);
		return 2;
	}

	double decay_time = nonlinear_equation(radioactivity, time, N, precision, interval1, interval2);
	printf("decay_time = %.5f\n", decay_time);
	double decay_rate = linear_equation(radioactivity, time, N);
	printf("decay_rate = %.5f\n", decay_rate);

	double time_difference = precision_analysis(radioactivity, time, N, interval1, interval2);
	printf("time_differences = %.5f\n", time_difference);

	return 0;
}
