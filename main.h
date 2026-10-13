#ifndef LAB2_MAIN_H
#define LAB2_MAIN_H

#include <stddef.h>

#define MAX_N 100
#define NOISE_LEVEL 0.05

// 1. Preparation
size_t experiment(double* radioactivity, double* time, double start_time, double end_time, double step);
void add_noise(double* radioactivity, size_t N);

#endif
