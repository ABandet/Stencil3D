#include "stencil.h"
#include <immintrin.h>

void stencil3d_vecto(float *a, float *b) {
    int i, j, k;
    float *aa, *bb;
    const int sizezx = SIZEZ * SIZEX;
    for (k = 1; k < SIZEZ - 1; k++)
        for (i = 1; i < SIZEX - 1; i++) {
            aa = &a[k * sizezx + i * SIZEY];
            bb = &b[k * sizezx + i * SIZEY];
            for (j = 1; j < SIZEY - 8; j += 8) {

#ifdef __AVX2__
                // aa[j] = (2 * bb[j] + bb[j + 1] + bb[j - 1]);
                __m256 two = _mm256_set1_ps(2);
                __m256 thirteen = _mm256_set1_ps(13);

                __m256 aaa, bbb, ccc;// = _mm256_loadu_ps(&aa[j]);
                __m256 bbj = _mm256_loadu_ps(&bb[j]);
                __m256 bbj1 = _mm256_loadu_ps(&bb[j + 1]);
                __m256 bbj2 = _mm256_loadu_ps(&bb[j - 1]);
                __m256 bbkj1 = _mm256_loadu_ps(&bb[(sizezx) + j + 1]);
                __m256 bbkj2 = _mm256_loadu_ps(&bb[(sizezx) + j - 1]);
                __m256 bbkij1 = _mm256_loadu_ps(&bb[(sizezx) + j + 1 + SIZEY]);
                __m256 bbkij2 = _mm256_loadu_ps(&bb[(sizezx) + j - 1 - SIZEY]);
                __m256 bbkkj1 = _mm256_loadu_ps(&bb[-(sizezx) + j + 1]);
                __m256 bbkkj2 = _mm256_loadu_ps(&bb[-(sizezx) + j - 1]);
                __m256 bbkkij1 = _mm256_loadu_ps(&bb[-(sizezx) + j + 1 + SIZEY]);
                __m256 bbkkij2 = _mm256_loadu_ps(&bb[-(sizezx) + j - 1 - SIZEY]);

                aaa = _mm256_mul_ps(bbj, two);
                aaa += _mm256_add_ps(bbj2, bbj1);

                // aa[j] += bb[SIZEY + j + 1] + bb[-SIZEY + j - 1];
                __m256 bbij1 = _mm256_loadu_ps(&bb[SIZEY + j + 1]);
                __m256 bbij2 = _mm256_loadu_ps(&bb[-SIZEY + j - 1]);
                aaa += _mm256_add_ps(bbij2, bbij1);


                ccc = _mm256_add_ps(bbkj2, bbkj1);
                bbb = _mm256_add_ps(bbkij2, bbkij1);
                aaa += _mm256_add_ps(bbkkj2, bbkkj1);
                ccc += _mm256_add_ps(bbkkij2, bbkkij1);

                aaa = _mm256_add_ps(aaa, bbb);
                aaa = _mm256_add_ps(aaa, ccc);
                aaa = _mm256_div_ps(aaa, thirteen);

                _mm256_storeu_ps(&aa[j], aaa);
#endif // __AVX2__
            }
        }
}
