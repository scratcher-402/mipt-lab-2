#include <math.h>
#include <stdio.h>
#include "main.h"

double nonlinear_equation(double *radioactivity, double *time, size_t N, double precision, double interval1, double interval2) {
    double func1 = model (radioactivity, time, N, interval1), func2 = model (radioactivity, time, N, interval2);

    double decay_time = solution (interval1, interval2, func1, func2, radioactivity, time, N, precision);

    return decay_time;
}

double solution (double int1, double int2, double func1, double func2, double *radioactivity, double *time, size_t N, double precision) {
    double point = (int1 + int2) / 2;

    if (fabs (int1 - int2) <= precision) {
        return point;
    }

    double func = model (radioactivity, time, N, point);

    if (func * func1 > 0) {
        return solution (point, int2, func, func2, radioactivity, time, N, precision);
    }
    
    return solution (int1, point, func1, func, radioactivity, time, N, precision);
}

double model(double *radioactivity, double *time, size_t N, double point) {
    double res = 0;
    for (size_t i = 0; i < N; ++i) {
        res += time[i] * exp (-1 * time[i] / point) * (radioactivity[i] - exp (-1 * time[i] / point));
    }
    return res;
}

double linear_equation (double *radioactivity, double *time, size_t N) {
    double numerator = 0, denominator = 0;

    for (size_t i = 0; i < N; ++i) {
        numerator += time[i] * time[i];
        denominator += time[i] * (1 - radioactivity[i]);
    }

    double decay_rate = numerator / denominator;

    return decay_rate;
}
