#include "stencil.h"

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

void stencil3d_jki(float *a, float *b) {
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
  for (k = 1; k < SIZEZ - 1; k++)
    for (i = 1; i < SIZEX - 1; i++)
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


void stencil3d_kji(float *a, float *b) {
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
