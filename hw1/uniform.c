#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626

int main() {
    int fs, n;
    double A, hz, phi;
    scanf("%d %d %lf %lf %lf", &fs, &n, &A, &hz, &phi);

    //Output n samples of the discrete that is obtained after uniform sampling of (eq) using the reate fs
    int *res = malloc(sizeof(int) * n);
    int n0 = 0;

    for(int i = 0; i < n; i++) {
        double freq = 1/(double)fs;
        double inside = 2*PI*hz * n0 * freq + phi;

        res[i] = A * cos(inside);
        n0 += 1;
    }

    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d",res[i]);
        if(i < n-1) {
            printf(",");
        }
    }
    printf("]");
    free(res);
    return 0;
}
