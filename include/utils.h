#ifndef STENCIL_UTILS_H
#define STENCIL_UTILS_H

double compute_throughput(const double time, const long long flops);
void init_matrix(float *a, float *b, const int size_x, const int size_y, const int size_z);
int bench_stencil_time(void (*f)(float *, float *), float *a, float *b, double time );
void bench_stencil_iterations( void (*f)(float*, float*), float *a, float *b, int iterations );

#endif //STENCIL_UTILS_H
