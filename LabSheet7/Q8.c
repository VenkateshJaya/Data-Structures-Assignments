#include <stdio.h>
#include <math.h>

int isAdjacentOne(int x) {
    if (x <= 9)
        return 1;
    int d1 = x % 10, d2;
    do {
        d2 = d1;
        x /= 10;
        d1 = x % 10;
        if (abs(d1 - d2) != 1)
            return 0;
    } while (x > 9);
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        if (isAdjacentOne(i))
            printf("%d ", i);
    }
}