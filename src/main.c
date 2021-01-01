#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <omp.h>
#include "stencil.h"
#include "utils.h"

/** TODO LIST :
 * check option (check with sequential version)
 * size options
 * variant selection
 * add timer
 * std output (time / throughput)
 */


int main(int argc, char **argv) {
    float *a, *b;
    int it;
    long long flops;
    char name[64];

    /* Initialization */
    a = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    b = (float *) malloc(sizeof(float) * SIZEX * SIZEY * SIZEZ);
    init_matrix(a, b, SIZEX, SIZEY, SIZEZ);
    flops = (SIZEX - 2) * (SIZEY - 2) * (SIZEZ - 2) * 14. * 2.;

    double cputime;
    double start = omp_get_wtime();

#ifdef IJK
    strcpy(name, "ijk");
    it = bench_stencil_time(stencil3d_ijk, a, b, TIME);
#elif IKJ
    strcpy(name, "ikj");
    it = bench_stencil_time(stencil3d_ikj, a, b, TIME);
#elif JIK
    strcpy(name, "jik");
    it = bench_stencil_time(stencil3d_jik, a, b, TIME);
#elif JKI
    strcpy(name, "jki");
    it = bench_stencil_time(stencil3d_jki, a, b, TIME);
#elif KIJ
    strcpy(name, "kij");
    it = bench_stencil_time(stencil3d_kij, a, b, TIME);
#elif KJI
    strcpy(name, "kji");
    it = bench_stencil_time(stencil3d_kji, a, b, TIME);
#elif VECTO
    strcpy(name, "vecto");
    it = bench_stencil_time(stencil3d_vecto, a, b, TIME);
#else
    strcpy(name, "original");
    it = bench_stencil_time(stencil3d_original, a, b, TIME);
#endif

    cputime = omp_get_wtime() - start;

    flops *= it;

    printf("# size : %d * %d * %d\n", SIZEX, SIZEY, SIZEZ);
    printf("# iterations : %d\n", it);
    printf("# flops : %lld\n", flops);
    printf("# time (s) : %lf\n", cputime);
    printf("# throughput (GFlops/s) : %lf\n\n", compute_throughput(cputime, flops));
    printf("# summary(csv) : %s,%d,%lf,%lf,%d,%lld\n", name, SIZEX, cputime, compute_throughput(cputime, flops), it,
           flops);

    free(a);
    free(b);
    return 0;
}
