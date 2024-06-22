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
    int *h, *x, lenh, lenx;

    h = readSignal(&lenh);
    x = readSignal(&lenx);

    int leny = lenx - lenh + 1;
    int *y = calloc(leny, sizeof(int));

    for(int d = 0; d < leny; d++) {
        for(int i = 0; i < lenh; i++) {
            y[d] += x[i + d] * h[i];
        }
    }

    printSignal(leny, y);

    free(x);
    free(h);
    free(y);
    return 0;
}
