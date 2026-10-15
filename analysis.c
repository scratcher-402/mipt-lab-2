#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "main.h"


double precision_analysis (double *radioactivity, double *time, size_t N, double interval1, double interval2) {
	double precision = 1e-5;
    for (size_t i = 10; i < N; i++) {
    	double decay_time = nonlinear_equation(radioactivity, time, i, precision, interval1, interval2);
   	    double decay_rate = linear_equation(radioactivity, time, i);

        double deviation1 = dev_exp(radioactivity, time, i, decay_time);
        double deviation2 = dev_linear(radioactivity, time, i, decay_rate);

        if (deviation2 > 2 * deviation1) {
            return time[i] - time[0];
        }
    }
    return time[N - 1] - time[0];
}

double dev_exp(double *radioactivity, double *time, size_t M, double decay_time) {
    double sum_residuals1 = 0;
    for (size_t i = 0; i < M; i++) {
        sum_residuals1 += pow(radioactivity[i] - exp(-time[i] / decay_time), 2);
    } 
    return sqrt(sum_residuals1 / M);
}

double dev_linear(double *radioactivity, double *time, size_t M, double decay_rate) {
    double sum_residuals2 = 0;
    for (size_t i = 0; i < M; i++) {
        sum_residuals2 += pow(radioactivity[i] - (1 - time[i] / decay_rate), 2);
    } 
    return sqrt(sum_residuals2 / M);
} 
