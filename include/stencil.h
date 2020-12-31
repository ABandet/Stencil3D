#ifndef PROJET_STENCIL_H
#define PROJET_STENCIL_H

#ifndef SIZE
  #define SIZEX 302
  #define SIZEY SIZEX
  #define SIZEZ SIZEX
#else
  #define SIZEX SIZE
  #define SIZEY SIZE
  #define SIZEZ SIZE
#endif

#ifndef TIME
  #define TIME 15
#endif


// original version
void stencil3d(float *a, float *b);

// Permutations
void stencil3d_ijk(float *a, const float *b);
void stencil3d_ikj(float *a, const float *b);
void stencil3d_jik(float *a, const float *b);
void stencil3d_jki(float *a, const float *b);
void stencil3d_kij(float *a, float *b);
void stencil3d_kji(float *a, const float *b);


#endif //PROJET_STENCIL_H
