#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numOfDigits(int a) {
    int count = 0;
    while (a) {
        count++;
        a /= 10;
    }
    return count;
}

int compare(const void *a, const void *b) {
    int *x = (int *)a, *y = (int *)b;
    int l = *x, m = *y;
    l = l * pow(10, numOfDigits(*y));
    l += *y;
    m = m * pow(10, numOfDigits(*x));
    m += *x;
    return m - l;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; ++i) {98oo9898o
        printf("%d", arr[i]);
    }
}
