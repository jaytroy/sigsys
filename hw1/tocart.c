#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double r,thet;
    scanf("%lf %lf", &r, &thet);

    double x,y;
    x = r * cos(thet);
    y = r * sin(thet);

    printf("%.2lf %.2lf\n", x, y);
}
