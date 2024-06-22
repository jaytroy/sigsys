#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626

int main() {
    //The sampling rate
    int fs;
    scanf("%d",&fs);

    //Amplitude, freqeuncy, phase shift
    double A1, hz1, phi1;
    scanf("%lf %lf %lf", &A1, &hz1, &phi1);

    double A2, hz2, phi2;
    scanf("%lf %lf %lf", &A2, &hz2, &phi2);

    int *res1 = malloc(sizeof(int) * fs*2);
    int *res2 = malloc(sizeof(int) * fs*2);
    int n0 = 0;

    for(int i = 0; i < 100; i++) {
        double freq = 1/(double)fs;
        double inside1 = 2*PI*hz1 * n0 * freq + phi1;
        double inside2 = 2*PI*hz2 * n0 * freq + phi2;

        res1[i] = A1 * cos(inside1);
        res2[i] = A2 * cos(inside2);

        n0 += 1;

        if(res1[i] != res2[i]) {
            printf("NO\n");
            return 0;
        }

    }

        printf("YES\n");

        free(res1);
        free(res2);
        return 0;
}
