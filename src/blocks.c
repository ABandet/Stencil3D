#include "stencil.h"
#include <immintrin.h>

#ifndef BSIZE
#define BSIZE 127
#endif

void stencil3d_block(float *a, float *b) {
    int i, j, k;
    int ii, jj, kk;
    float *aa, *bb;
    const int sizezx = SIZEZ * SIZEX;
#pragma omp parallel for collapse(3) private(i,j,k,ii,jj,kk, aa, bb) schedule(dynamic) default(shared)
    for (k = 1; k < SIZEZ - 1 - BSIZE; k += BSIZE)
            for (j = 1; j < SIZEY - 1 - BSIZE; j += BSIZE)
        for (i = 1; i < SIZEX - 1 - BSIZE; i += BSIZE)
                for (kk = 0; kk < BSIZE; kk++)
                    for (ii = 0; ii < BSIZE; ii++) {
                        aa = &a[(k+kk) * sizezx + (i+ii) * SIZEY];
                        bb = &b[(k+kk) * sizezx + (i+ii) * SIZEY];
                        for (jj = j; jj < j+BSIZE; jj+=8) {
#ifdef __AVX2__
                            // aa[j] = (2 * bb[j] + bb[j + 1] + bb[j - 1]);
                            __m256 two = _mm256_set1_ps(2);
                            __m256 thirteen = _mm256_set1_ps(13);

                            __m256 aaa = _mm256_loadu_ps(&aa[(jj)]);
                            __m256 bbj = _mm256_loadu_ps(&bb[(jj)]);
                            __m256 bbj1 = _mm256_loadu_ps(&bb[jj + 1]);
                            __m256 bbj2 = _mm256_loadu_ps(&bb[jj - 1]);

                            aaa = _mm256_mul_ps(aaa, two);
                            aaa = _mm256_add_ps(aaa, bbj);
                            aaa = _mm256_add_ps(aaa, bbj1);
                            aaa = _mm256_add_ps(aaa, bbj2);

                            // aa[j] += bb[SIZEY + j + 1] + bb[-SIZEY + j - 1];
                            __m256 bbij1 = _mm256_loadu_ps(&bb[SIZEY + jj + 1]);
                            __m256 bbij2 = _mm256_loadu_ps(&bb[-SIZEY + jj - 1]);
                            aaa = _mm256_add_ps(aaa, bbij1);
                            aaa = _mm256_add_ps(aaa, bbij2);

                            __m256 bbkj1 = _mm256_loadu_ps(&bb[(sizezx) + jj + 1]);
                            __m256 bbkj2 = _mm256_loadu_ps(&bb[(sizezx) + jj - 1]);
                            __m256 bbkij1 = _mm256_loadu_ps(&bb[(sizezx) + jj + 1 + SIZEY]);
                            __m256 bbkij2 = _mm256_loadu_ps(&bb[(sizezx) + jj - 1 - SIZEY]);
                            __m256 bbkkj1 = _mm256_loadu_ps(&bb[-(sizezx) + jj + 1]);
                            __m256 bbkkj2 = _mm256_loadu_ps(&bb[-(sizezx) + jj - 1]);
                            __m256 bbkkij1 = _mm256_loadu_ps(&bb[-(sizezx) + jj + 1 + SIZEY]);
                            __m256 bbkkij2 = _mm256_loadu_ps(&bb[-(sizezx) + jj - 1 - SIZEY]);

                            aaa = _mm256_add_ps(aaa, bbkj1);
                            aaa = _mm256_add_ps(aaa, bbkj2);
                            aaa = _mm256_add_ps(aaa, bbkij1);
                            aaa = _mm256_add_ps(aaa, bbkij2);
                            aaa = _mm256_add_ps(aaa, bbkkj1);
                            aaa = _mm256_add_ps(aaa, bbkkj2);
                            aaa = _mm256_add_ps(aaa, bbkkij1);
                            aaa = _mm256_add_ps(aaa, bbkkij2);

                            aaa = _mm256_div_ps(aaa, thirteen);

                            _mm256_storeu_ps(&aa[jj], aaa);
#endif // __AVX2__
                        }
                    }

}