#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define abs(a) ((a)>0?(a):-(a))
#define min(a,b) ((a>b)?(b):(a))
#define SIZEX 50
#define SIZEY 50
#define SIZEZ 50

void stencil3d(float *a, float *b) {
  int i,j,k;
  for (j=1; j<SIZEY-1; j++)
    for (i=1; i<SIZEX-1; i++)
      for (k=1; k<SIZEZ-1; k++)
        a[k*SIZEZ*SIZEX+i*SIZEY+j] = (2*b[k*SIZEZ*SIZEX+i*SIZEY+j]+
                                      b[k*SIZEZ*SIZEX+i*SIZEY+j+1]+
                                      b[k*SIZEZ*SIZEX+i*SIZEY+j-1]+
                                      b[k*SIZEZ*SIZEX+(i+1)*SIZEY+j+1]+
                                      b[k*SIZEZ*SIZEX+(i-1)*SIZEY+j-1]+
                                      b[(k+1)*SIZEZ*SIZEX+i*SIZEY+j+1]+
                                      b[(k+1)*SIZEZ*SIZEX+i*SIZEY+j-1]+
                                      b[(k+1)*SIZEZ*SIZEX+(i+1)*SIZEY+j+1]+
                                      b[(k+1)*SIZEZ*SIZEX+(i-1)*SIZEY+j-1]+
                                      b[(k-1)*SIZEZ*SIZEX+i*SIZEY+j+1]+
                                      b[(k-1)*SIZEZ*SIZEX+i*SIZEY+j-1]+
                                      b[(k-1)*SIZEZ*SIZEX+(i+1)*SIZEY+j+1]+
                                      b[(k-1)*SIZEZ*SIZEX+(i-1)*SIZEY+j-1])/13;

}

int main() {
  int i,j,k,h;
  float *a,*b;
  a=(float *)malloc(sizeof(float)*SIZEX*SIZEY*SIZEZ);
  b=(float*)malloc(sizeof(float)*SIZEX*SIZEY*SIZEZ);
  float s=0;
  /* Initialization */
  for (i=0; i<SIZEX; i++)
    for (j=0; j<SIZEY; j++)
      for (k=0; k<SIZEZ; k++)
        a[k*SIZEZ*SIZEX+i*SIZEY+j]=b[k*SIZEZ*SIZEX+i*SIZEY+j]=(j+1.)/((k+1)*(i+1));
  for (j=SIZEY/4; j<SIZEY/2; j++)
    for (i=SIZEX/4; i<SIZEX/2; i++)
      b[i*SIZEY+j]=a[i*SIZEY+j]=1;
  for(h=0;h<100;h++) {
    stencil3d(a,b);
    for (i=0; i<SIZEX; i++)
      for (j=0; j<SIZEY; j++)
        for (k=0; k<SIZEZ; k++)
          s+=a[k*SIZEZ*SIZEX+i*SIZEY+j];
    stencil3d(b,a);
    fprintf(stderr,".");
  }
  fprintf(stderr,"%f\n",s);

  free(a);
  free(b);
  return 0;
}
