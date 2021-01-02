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
void stencil3d_ijk(float *a, float *b);
void stencil3d_ikj(float *a, float *b);
void stencil3d_jik(float *a, float *b);
void stencil3d_jki(float *a, float *b);
void stencil3d_kij(float *a, float *b);
void stencil3d_kji(float *a, float *b);

// vecto
void stencil3d_vecto(float *a, float *b);

// block
void stencil3d_block(float *a, float *b);


#endif //PROJET_STENCIL_H
