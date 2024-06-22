#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626

typedef struct signal {
    float A, hz, phi;
} Signal;

int main() {
    //Sampling frequency and number of samples
    int fs, n;
    scanf("%d %d",&fs,&n);

    //Number of signals
    int m;
    scanf("%d",&m);

    //An array to store all the signals
    Signal *signals = malloc(sizeof(Signal) * m);

    //Map the signals
    for(int i = 0; i < m; i++) {
        Signal s;
        scanf("%f %f %f", &s.A,&s.hz,&s.phi);
        signals[i] = s;
    }

    //Will hold resulting values
    double *res = malloc(sizeof(double) * n);

    //Iterate over signal range
    for(int i = 0; i < n; i++) {
        double val = 0;

        //Evaluate each signal and add them together to get the coposite value
        for(int j = 0; j < m; j++) {
            double t = i / (double)fs;
            val += signals[j].A * cos(2*PI*signals[j].hz * t + signals[j].phi);
        }
        res[i] = val;
    }

    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", (int)res[i]);
        if(i < n - 1) {
            printf(",");
        }
    }
    printf("]");

    free(signals);
    free(res);
    return 0;
}
