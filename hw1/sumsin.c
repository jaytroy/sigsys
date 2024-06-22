#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float f, a0, phi0, a1, phi1;
    scanf("%f %f %f %f %f", &f, &a0, &phi0, &a1, &phi1);


    float real, imag;
    real = a0 * cos(phi0) + a1 * cos(phi1);
    imag = a0 * sin(phi0) + a1 * sin(phi1);
    float A, Phi;
    A = sqrt(real * real + imag * imag);
    Phi = atan2(imag,real);

    if(round(A * 100) == 0) {
        printf("x(t)=0.00");
        return 0;
    }

    printf("x(t)=%.2f*cos(2*pi*%.2f*t+%.2f)\n",A,f,Phi);
    return 0;
}
