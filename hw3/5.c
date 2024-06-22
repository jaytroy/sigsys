#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359
#define PRIME 40961
#define OMEGA 243
#define MAX 8192
typedef unsigned int uint;

uint powmod(uint base, uint exponent, uint prime) {
  /* This function computes: base raised to the power exponent modulus prime
   * in math notation: (base^exponent) mod prime
   */
  uint pm = 1;
  base = base%prime;
  while (exponent > 0) {
    if (exponent%2 == 1) { /* exponent is odd */
      pm = (pm*base)%prime;
    }
    exponent /= 2;
    base = (base*base)%prime;
  }
  return pm;
}

uint *readSignal(int *len) {
  uint *x;
  char c;
  scanf("%d:", len);
  x = calloc(*len, sizeof(uint));
  do c = getchar(); while (c != '[');
  if (*len > 0) {
    scanf("%u", &x[0]);
    for (int i=1; i < *len; i++) scanf(",%u", &x[i]);
  }
  do c = getchar(); while (c != ']');
  return x;
}

void printSignal(int len, uint *x) {
  printf("%d: [", len);
  if (len > 0) {
    printf("%u", x[0]);
    for (int i=1; i < len; i++) printf(",%u", x[i]);
  }
  printf("]\n");
}

void ntt(uint *a, int len) {
    if(len == 1) return;

    uint *even = malloc(sizeof(uint) * (len/2));
    uint *odd = malloc(sizeof(uint) * (len/2));
    for(int i = 0; i < len/2; i++) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    ntt(even, len/2);
    ntt(odd, len/2);

    uint wk = 1;
    for(int i = 0; i < len/2; i++) {
        wk = powmod(OMEGA, i * (MAX/len), PRIME);
        uint t = (wk * odd[i]) % PRIME;
        a[i] = (even[i] + t) % PRIME;
        a[i + len/2] = (even[i] - t + PRIME) % PRIME;
    }

    free(even);
    free(odd);
}

int main() {//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    uint *h;
    int lenh;

    h = readSignal(&lenh);

    ntt(h,lenh);

    printSignal(lenh,h);

    free(h);
    return 0;
}
