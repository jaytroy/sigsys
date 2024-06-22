#include <stdio.h>
#include <stdlib.h>

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


int main() {
    int lenh, lenx, *h, *x;

    h = readSignal(&lenh);
    x = readSignal(&lenx);

    int total = lenh + lenx - 1;
    int *o = calloc(total * 100,sizeof(int));
    for(int i = 0; i < lenh; i++) { //Iterate over the filter
        for(int j = 0; j < lenx; j++) { //Iterate over the signal
            o[i+j] += h[i] * x[j];
        }
    }

    printSignal(total, o);

    free(x);
    free(h);
    free(o);

    return 0;
}
