#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double f0, f1;
    scanf("%lf %lf", &f0, &f1);

    printf("%lf %lf\n", fabs((f0 - f1) / 2), fabs((f0 + f1) / 2));
    return 0;
}
