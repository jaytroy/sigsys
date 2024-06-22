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

void printSignal(int len, int *x) {
  printf("%d: [", len);
  if (len > 0) {
    printf("%d", x[0]);
    for (int i=1; i < len; i++) printf(",%d", x[i]);
  }
  printf("]\n");
}

void findFIR(int *x, int lenx, int *y, int leny, int *h, int lenh) {
    for(int i = 0; i < lenh; i++) {
        for(int j = 0; j < i; j++) {
          if(i-j < lenx) y[i] -= h[j] * x[i - j];
        }
        h[i] = y[i] / x[0];
    }
}

int *linfil(int lenh, int lenx, int *h, int *x) {
  int total = lenh + lenx - 1;
    int *o = calloc(total * 100,sizeof(int));
    for(int i = 0; i < lenh; i++) { //Iterate over the filter
        for(int j = 0; j < lenx; j++) { //Iterate over the signal
            o[i+j] += h[i] * x[j];
        }
    }
    return o;
}

int main() {
    int *x, *y, *h, lenx, leny, lenh;

    x = readSignal(&lenx); //Read signal
    y = readSignal(&leny); //Read output

    int *y2 = malloc(sizeof(int) * leny);
    for(int i = 0; i < leny; i++) { //copy contents as we're gonna modify y
      y2[i] = y[i];
    }

    lenh = leny - lenx + 1; //Find length of filter
    h = calloc(lenh + 1,sizeof(int));

    findFIR(x,lenx,y,leny,h,lenh); //find h
    int *o = linfil(lenh,lenx,h,x); //find result

    //printSignal(leny,o);
    //printSignal(leny,y2);
    int flag = 0;
    for(int i = 0; i < leny; i++) {
      if(o[i] != y2[i]) {
        flag = 1;
        break;
      }
    }

    if(flag == 0) {
      printSignal(lenh,h);
    } else {
      printf("NO FIR\n");
    }

    free(y2);
    free(o);
    free(x);
    free(y);
    free(h);
    return 0;
}
