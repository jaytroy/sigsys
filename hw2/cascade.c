#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //FOR EXERCISE 2, SWITCH ALL TO 2 AND REMOVE SCANF
    int all; //All doesn't count final signal, only filters
    scanf("%d",&all);

    int *lens = malloc((all) * sizeof(int)); //Array for sizes of filters
    int **sigs = malloc((all) * sizeof(int *)); //Matrix for storing filters

    for(int i = 0; i < all; i++) { //Map the arrays and lengths
        sigs[i] = readSignal(&lens[i]);
    }

    int *x, lenx; //Size and array for signal
    x = readSignal(&lenx); //Read the signal

    for(int z = 0; z < all; z++) { //Iterate over all filters
        int leno = lenx + lens[z] - 1;
        int *o = calloc(leno, sizeof(int)); //Array for output

        for(int i = 0; i < lens[z]; i++) { //Iterate over the filter
            for(int j = 0; j < lenx; j++) { //Iterate over the signal
                o[i+j] += sigs[z][i] * x[j];
            }
        }

        free(x);
        x = o;
        lenx = leno;
    }

    printSignal(lenx, x);

    for(int i = 0; i < all; i++) {
        free(sigs[i]);
    }
    free(sigs);
    free(lens);
    free(x);

    return 0;
}
