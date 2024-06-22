#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int x, int y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int lcm(int x, int y) {
    return (x/gcd(x,y)) * y;
}

int main() {
    int n;
    scanf("%d", &n);

    //Define arrays for n signals. Structs are too finicky
    int *T = malloc(sizeof(int) * n);

    //Scan input
    for(int i = 0; i < n; i++) {
        scanf("%*d %d %*lf",&T[i]);
    }

    //Find lowest common multiple
    int res = 1;
    for(int i = 0; i < n; i++) {
        res = lcm(res,T[i]);
    }

    printf("%d\n",res);

    free(T);
    return 0;
}
