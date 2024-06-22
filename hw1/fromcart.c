#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);

    double r, thet;
    r = sqrt((x * x) + (y * y));
    thet = atan2(y, x);

    if(x < 0 && y == 0) {
        thet = -3.14;
    }

    printf("%.2lf %.2lf", r, thet);

    return 0;
}
