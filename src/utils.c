#include "utils.h"
#include "stencil.h"
#include <time.h>
#include <omp.h>
#include <stdio.h>


double compute_throughput(const double time, const long long flops) {
  double seconds = time;
  double giga_operation = flops / 1000000000.0;

  return giga_operation / seconds;
}

void init_matrix(float *a, float *b, const int size_x, const int size_y, const int size_z) {
  int i, j, k;
  for (i = 0; i < size_x; i++)
    for (j = 0; j < size_y; j++)
      for (k = 0; k < size_z; k++)
        a[k * size_z * size_x + i * size_y + j] = b[k * size_z * size_x + i * size_y + j] =
                (j + 1.) / ((k + 1) * (i + 1));

  for (j = size_y / 4; j < size_y / 2; j++)
    for (i = size_x / 4; i < size_x / 2; i++)
      b[i * size_y + j] = a[i * size_y + j] = 1;
}

int bench_stencil_time(void (*f)(float *, float *), float *a, float *b, double time) {
  double start;
  int count = 0;

  start = omp_get_wtime();
  while ((omp_get_wtime() - start)  < time) {
    count++;
    f(a, b);
    f(b, a);
  }

  return count;
}

void bench_stencil_iterations(void (*f)(float *, float *), float *a, float *b, int iterations) {
  for (int i = 0; i < iterations; i++) {
    f(a, b);
    f(b, a);
  }
}

int same_matrix(float *m1, float *m2, int size) {
    for (int i = 0; i < size; i++){
        if (m1[i] >= m2[i]+0.1 || m1[i] <= m2[i]-0.1) {
            printf("Wrong value at %d (%f, %f)\n", i, m1[i], m2[i]);
            return 0;
        }
    }

    return 1;
}

int test_function(void (*f)(float *, float *)) {
    float *a, *b, *aa, *bb;
    a = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    b = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    aa = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    bb = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    init_matrix(a, b, SIZEX, SIZEY, SIZEZ);
    init_matrix(aa, bb, SIZEX, SIZEY, SIZEZ);
    f(a,b);
    stencil3d(aa,bb);
    return same_matrix(a, aa, SIZEX*SIZEY*SIZEZ);
}