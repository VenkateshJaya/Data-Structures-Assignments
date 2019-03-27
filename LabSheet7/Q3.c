#include <stdio.h>

int main()
{
    int n, src = -1, j, count = 0;
    scanf("%d", &n);
    int arr[n], visited[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        arr[i]--;
        visited[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        j = i;

        while (!visited[j]) {
            visited[j] = 1;
            if (j == arr[j]) {
                if (src == -1)
                    src = j;
                else {
                    count++;
                    arr[j] = src;
                    break;
                }
            }
            j = arr[j];
        }
        if (src != -1 && j == i) {
            arr[j] = src;
        }
        else if (src == -1 && j == i) {
            for (int k = 0; k < n; ++k) {
                if (!visited[k]) {
                    arr[j] = k;
                    break;
                }
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i] + 1);
    }
}