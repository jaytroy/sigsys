#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626

int main() {
    double A, f, phi;
    scanf("%lf %lf %lf", &A, &f, &phi);

    double x0, x1, x2;
    scanf("%lf %lf %lf", &x0, &x1, &x2);

    //Find distances between the mic and the posits
    double dist1, dist2;
    dist1 = fabs(x2 - x0);
    dist2 = fabs(x2 - x1);

    //Calculate phase
    double phi1, phi2;
    phi1 = dist1 * (2 * PI * f) / 343;
    phi2 = dist2 * (2 * PI * f) / 343;
    printf("%lf %lf", phi1, phi2);

    double real, imag;
    real = A * cos(phi1) + A * cos(phi2);
    imag = A * sin(phi1) + A * sin(phi2);

    double Af;
    Af = sqrt(real * real + imag * imag);

    printf("%.2lf", Af);
}
