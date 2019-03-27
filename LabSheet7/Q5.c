#include <stdio.h>

void BFS(int n, int arr[][n], int dest[n], int src) {
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
                queue[++tail] = i;
                dest[i] = dest[u] + 1;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, m, s, t, initDist, count = 0;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int arr[n][n], dest[n];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            arr[i][j] = arr[j][i] = 0;
        }
    }
    s--;
    t--;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        arr[u - 1][v - 1] = arr[v - 1][u - 1] = 1;
    }
    BFS(n, arr, dest, s);
    initDist = dest[t];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!arr[i][j]) {
                arr[i][j] = arr[j][i] = 1;
                BFS(n, arr, dest, s);
                if (dest[t] == initDist)
                    count++;
                arr[i][j] = arr[j][i] = 0;
            }
        }
    }
    printf("%d", count);
}