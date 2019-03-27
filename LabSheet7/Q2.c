#include <stdio.h>

void floyd(int n, int arr[n][n], int cost[n]) {
    int color[n], ct = 0, ways = 1, min, temp;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][k] && arr[k][j] && arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
        color[k] = 0;
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i][i]) {
            color[i] = 1;
            ct += cost[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            temp = 1;
            min = cost[i];
            color[i] = 1;
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] && arr[j][i]) {
                    color[j] = 1;
                    if (min > cost[j])
                        min = cost[j];
                }
            }
            ct += min;
            for (int j = 0; j < n; ++j) {
                if (cost[j] == min && arr[i][j] && arr[j][i])
                    temp++;
            }
            ways *= temp;
        }
    }
    printf("%d %d", ct, ways);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int cost[n], arr[n][n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]);
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        arr[u - 1][v - 1] = 1;
    }
    floyd(n, arr, cost);
}