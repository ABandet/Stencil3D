#include "stencil.h"
#include <immintrin.h>
#include <stdio.h>

void stencil3d_ijk(float *a, const float *b) {
  int i, j, k;
  for (i = 1; i < SIZEX - 1; i++)
    for (j = 1; j < SIZEY - 1; j++)
      for (k = 1; k < SIZEZ - 1; k++)
        a[k * SIZEZ * SIZEX + i * SIZEY + j] = (2 * b[k * SIZEZ * SIZEX + i * SIZEY + j] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[k * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1]) / 13;
}

void stencil3d_ikj(float *a, const float *b) {
  int i, j, k;
  for (i = 1; i < SIZEX - 1; i++)
    for (k = 1; k < SIZEZ - 1; k++)
      for (j = 1; j < SIZEY - 1; j++)
        a[k * SIZEZ * SIZEX + i * SIZEY + j] = (2 * b[k * SIZEZ * SIZEX + i * SIZEY + j] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[k * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1]) / 13;
}

void stencil3d_jik(float *a, const float *b) {
  int i, j, k;
  for (j = 1; j < SIZEY - 1; j++)
    for (i = 1; i < SIZEX - 1; i++)
      for (k = 1; k < SIZEZ - 1; k++)
        a[k * SIZEZ * SIZEX + i * SIZEY + j] = (2 * b[k * SIZEZ * SIZEX + i * SIZEY + j] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[k * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1]) / 13;
}

void stencil3d_jki(float *a, const float *b) {
  int i, j, k;
  for (j = 1; j < SIZEY - 1; j++)
    for (k = 1; k < SIZEZ - 1; k++)
      for (i = 1; i < SIZEX - 1; i++)
        a[k * SIZEZ * SIZEX + i * SIZEY + j] = (2 * b[k * SIZEZ * SIZEX + i * SIZEY + j] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[k * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1]) / 13;
}

void stencil3d_kij(float *a, float *b) {
  int i, j, k;
  float *aa, *bb;
  float sum;
//#pragma omp parallel for collapse(2)
  for (k = 1; k < SIZEZ - 1; k++)
    for (i = 1; i < SIZEX - 1; i++) {
      aa = &a[k * SIZEZ * SIZEX + i * SIZEY];
      bb = &b[k * SIZEZ * SIZEX + i * SIZEY];
      for (j = 1; j < SIZEY - 8; j+=8) {

        // aa[j] = (2 * bb[j] + bb[j + 1] + bb[j - 1]);
        __m256 two = _mm256_set1_ps(2);
        __m256 thirteen = _mm256_set1_ps(13);

        __m256 aaa = _mm256_loadu_ps(&aa[j]);
        __m256 bbj = _mm256_loadu_ps(&bb[j]);
        __m256 bbj1 = _mm256_loadu_ps(&bb[j+1]);
        __m256 bbj2 = _mm256_loadu_ps(&bb[j-1]);

        aaa = _mm256_mul_ps(aaa, two);
        aaa = _mm256_add_ps(aaa, bbj);
        aaa = _mm256_add_ps(aaa, bbj1);
        aaa = _mm256_add_ps(aaa, bbj2);

        // aa[j] += bb[SIZEY + j + 1] + bb[-SIZEY + j - 1];
        __m256 bbij1 = _mm256_loadu_ps(&bb[SIZEY+j+1]);
        __m256 bbij2 = _mm256_loadu_ps(&bb[-SIZEY+j-1]);
        aaa = _mm256_add_ps(aaa, bbij1);
        aaa = _mm256_add_ps(aaa, bbij2);

        __m256 bbkj1 = _mm256_loadu_ps(&bb[(SIZEZ * SIZEX)+j+1]);
        __m256 bbkj2 = _mm256_loadu_ps(&bb[(SIZEZ * SIZEX)+j-1]);
        __m256 bbkij1 = _mm256_loadu_ps(&bb[(SIZEZ * SIZEX)+j+1+SIZEY]);
        __m256 bbkij2 = _mm256_loadu_ps(&bb[(SIZEZ * SIZEX)+j-1-SIZEY]);
        __m256 bbkkj1 = _mm256_loadu_ps(&bb[-(SIZEZ * SIZEX)+j+1]);
        __m256 bbkkj2 = _mm256_loadu_ps(&bb[-(SIZEZ * SIZEX)+j-1]);
        __m256 bbkkij1 = _mm256_loadu_ps(&bb[-(SIZEZ * SIZEX)+j+1+SIZEY]);
        __m256 bbkkij2 = _mm256_loadu_ps(&bb[-(SIZEZ * SIZEX)+j-1-SIZEY]);

        aaa = _mm256_add_ps(aaa, bbkj1);
        aaa = _mm256_add_ps(aaa, bbkj2);
        aaa = _mm256_add_ps(aaa, bbkij1);
        aaa = _mm256_add_ps(aaa, bbkij2);
        aaa = _mm256_add_ps(aaa, bbkkj1);
        aaa = _mm256_add_ps(aaa, bbkkj2);
        aaa = _mm256_add_ps(aaa, bbkkij1);
        aaa = _mm256_add_ps(aaa, bbkkij2);

        aaa = _mm256_div_ps(aaa, thirteen);

        _mm256_storeu_ps(&aa[j], aaa);
      }
    }
}


void stencil3d_kji(float *a, const float *b) {
  int i, j, k;
  for (k = 1; k < SIZEZ - 1; k++)
    for (j = 1; j < SIZEY - 1; j++)
      for (i = 1; i < SIZEX - 1; i++)
        a[k * SIZEZ * SIZEX + i * SIZEY + j] = (2 * b[k * SIZEZ * SIZEX + i * SIZEY + j] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[k * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[k * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k + 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + i * SIZEY + j - 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i + 1) * SIZEY + j + 1] +
                                                b[(k - 1) * SIZEZ * SIZEX + (i - 1) * SIZEY + j - 1]) / 13;
}
