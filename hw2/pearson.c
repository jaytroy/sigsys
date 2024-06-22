#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define pi 3.14159265359

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

void printSignal(int len, double *x) {
  printf("%d: [", len);
  if (len > 0) {
    printf("%.5lf", x[0]);
    for (int i=1; i < len; i++) printf(",%.5lf", x[i]);
  }
  printf("]\n");
}

double *pearson(int *h, int *x, int lenh, int lenx) {
    double hbar = 0;
    for(int i = 0; i < lenh; i++) { //hbar is constant, calculate outside loop
      hbar += h[i];
    }
    hbar /= lenh;

    int leny = lenx - lenh + 1;
    double *y = calloc(leny, sizeof(double));

    for(int d = 0; d < leny; d++) {
        double xbar = 0;
        for(int i = 0; i < lenh; i++) { //xbar is not constant
            xbar += x[i+d];
        }
        xbar /= lenh;

        double top = 0, bottom1 = 0, bottom2 = 0;

        for(int i = 0; i < lenh; i++) {
            top += (x[i + d] - xbar) * (h[i] - hbar);
            bottom1 += pow(x[i+d]-xbar,2);
            bottom2 += pow(h[i]-hbar,2);
        }
        y[d] = top / (sqrt(bottom1)*sqrt(bottom2));
    }

    return y;
}

int main() {
    double num;
    scanf("%lf", &num);

    int *h, *x, lenh, lenx;

    h = readSignal(&lenh);
    x = readSignal(&lenx);

    double *y = pearson(h,x,lenh,lenx);

    printf("%.30lf %.30lf\n",y[1], num);
    printf("%.30lf %.30lf\n",y[7], num);

    for(int i = 0; i < lenx - lenh +  1; i++) {
      //printf("%lf\n",y[i]);
      if(y[i] > num - 0.0000005) {
        printf("%d %.5lf\n", i, y[i]);
      }
    }

    free(y);
    free(h);
    free(x);

    return 0;
}
