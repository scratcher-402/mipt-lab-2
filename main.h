#ifndef LAB2_MAIN_H
#define LAB2_MAIN_H

#include <stddef.h>

#define MAX_N 100
#define NOISE_LEVEL 0.05

// 1. Preparation
size_t experiment(double* radioactivity, double* time, double start_time, double end_time, double step);
void add_noise(double* radioactivity, size_t N);

// 2. Processing
double nonlinear_equation(double *radioactivity, double *time, size_t N, double precision, double interval1, double interval2);
double solution (double int1, double int2, double func1, double func2, double *radioactivity, double *time, size_t N, double precision);
double model(double *radioactivity, double *time, size_t N, double point);
double linear_equation(double *radioactivity, double *time, size_t N);

// 3. Analysis
double precision_analysis (double *radioactivity, double *time, size_t N, double interval1, double interval2);
double dev_exp(double *radioactivity, double *time, size_t M, double decay_time);
double dev_linear(double *radioactivity, double *time, size_t M, double decay_rate); 

// Other functions
void print_experiment_data(const double* radioactivity, const double* time, size_t N);

#endif
