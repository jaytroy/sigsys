#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#define PI 3.14159265359

int *readSignal(int *len) {
  int *x;
  char c;
  scanf("%d:", len);
  x = calloc(*len, sizeof(int));
  do c = getchar(); while (c != '[');
  if (*len > 0) {
    scanf("%d", &x[0]);
    for (int i=1; i < *len; i++) scanf(",%d", &x[i]);
  }
  do c = getchar(); while (c != ']');
  return x;
}

void printSignal(int len, int *x) {
  printf("%d: [", len);
  if (len > 0) {
    printf("%d", x[0]);
    for (int i=1; i < len; i++) printf(",%d", x[i]);
  }
  printf("]\n");
}

void printComplexSignal(int len, complex double *y) {
  printf("%d: [", len);
  if (len > 0) {
    printf("%lf + %lf*i", creal(y[0]), cimag(y[0]));
    for (int i = 1; i < len; i++) {
      printf(", %lf + %lf*i", creal(y[i]), cimag(y[i]));
    }
  }
  printf("]\n");
}


void fft2(complex double *a, int omega) {
    if(omega == 1) return;

    //Split even and odd
    complex double *even = malloc(sizeof(complex double) * (omega/2));
    complex double *odd = malloc(sizeof(complex double) * (omega/2));
    for(int i = 0; i < omega / 2; i++) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    //Recursive fft
    fft2(even, omega / 2);
    fft2(odd, omega / 2);

    //Combine
    for(int i = 0; i < omega / 2; i++) {
        a[i] = even[i] + cexp(-I * 2 * PI * i / omega) * odd[i];
        a[i + omega / 2] = even[i] - cexp(-I * 2 * PI * i / omega) * odd[i];
    }

    free(even);
    free(odd);
}

//Inverse fft
void ifft(complex double *a, int omega) {
    //Do the thing
    for(int i = 0; i < omega; i++) {
        a[i] = conj(a[i]);
    }

    fft2(a, omega);

    //Do the thing again
    for(int i = 0; i < omega; i++) {
        a[i] = conj(a[i]);
    }

    //multiply by whatever to scale
    for(int i = 0; i < omega; i++) {
        a[i] /= omega;
    }
}

void convolve(complex double *sig1, complex double *sig2, complex double *res, int omega) {
    fft2(sig1, omega);
    fft2(sig2, omega);

    //Multiply signals
    for(int i = 0; i < omega; i++) res[i] = sig1[i] * sig2[i];

    //Then, inverse
    ifft(res, omega);
}


int main() {
    int *h, *x, lenh, lenx;

    h = readSignal(&lenh);
    x = readSignal(&lenx);

    //Our omega
    int n = 1;
    while(n < lenh + lenx - 1) {
        n *= 2;
    }

    //Pad arrays with 0s
    complex double *hx = calloc(n, sizeof(complex double));
    for(int i = 0; i < lenh; i++) {
        hx[i] = h[i];
    }
    complex double *xx = calloc(n, sizeof(complex double));
    for(int i = 0; i < lenx; i++) {
        xx[i] = x[i];
    }

    //fft2(hx,n);
    //printComplexSignal(n,hx);

    //printf("\n");
    complex double *res = malloc(sizeof(complex double) * n + 10);
    convolve(hx,xx,res,n);
    //printComplexSignal(lenh + lenx - 1, res);

    int *new = malloc(sizeof(int) * (lenx + lenh - 1) + 10);
    for(int i = 0; i < lenh + lenx - 1; i++) {
        new[i] = (int) round(creal(res[i]));
    }
    printSignal(lenx+lenh - 1,new);



   // printf("%d\n\n",n);
    //printSignal(lenh + lenx - 1, res2);

    //printf("\n");

    free(h);
    free(x);
    free(hx);
    free(xx);
    free(res);
    free(new);
}
