#include <stdio.h>

void BFS(int n, int arr[][n], int dest[n], int src, int x) {
    int u, queue[n], head = 0, tail = 0, visited[n];
    for (int i = 0; i < n; ++i) {
        dest[i] = -1;
        visited[i] = 0;
    }

    dest[src] = 0;
    visited[src] = 1;
    queue[head] = src;
    while (head <= tail) {
        u = queue[head++];
        for (int i = 0; i < n; ++i) {
            if (arr[u][i] && !visited[i]) {
                if (i != x)
                    queue[++tail] = i;
                dest[i] = dest[u] + 1;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, x, sum = 0;
    scanf("%d%d", &n, &x);
    x--;
    int arr[n][n], dest1[n], dest2[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        arr[u - 1][v - 1] = arr[v - 1][u - 1] = 1;
    }
    BFS(n, arr, dest1, x, n);
    BFS(n, arr, dest2, 0, -1);
    for (int i = 0; i < n; ++i) {
        if (dest1[i] == -1)
            continue;

        if (dest2[i] + dest1[i] != dest1[0] && dest1[i] > dest2[i]) {
            if (2 * dest2[i] > sum)
                sum = 2 * dest2[i];
        }

        if (dest1[i] + dest2[i] == dest1[0] && !dest1[i]) {
            if (dest2[i] * 2 > sum)
                sum = 2 * dest2[i];
        }
    }
    printf("%d", sum);
}