#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int first, second;
} Pair;

int compare(const void *a, const void *b) {
    return (((Pair *)a) -> first  - ((Pair *)b) -> first);
}

int main()
{
    int n, left = 0, count = 0;
    scanf("%d", &n);
    Pair arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }

    qsort(arr, n, sizeof(Pair), compare);
    for (int i = 0; i < n; ++i) {
        if (i < arr[i].second) {
            left++;
            count += (arr[i].second - i);
        }
        else if (i > arr[i].second) {
            count += (i - arr[i].second - left);
        }
    }
    printf("%d", count);
}