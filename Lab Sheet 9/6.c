#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int n;
int visited[N][N];

int dfs(int i, int j, int grid[][n]){
    visited[i][j] = 1;
    if(i==n-1 && j==n-1) return 1;
    int ans = 0;
    if(!visited[i+1][j] && i+1<=n-1 && grid[i+1][j] <= grid[i][j]) ans = dfs(i+1, j, grid);
    if(!visited[i][j+1] && j+1<=n-1 && grid[i][j+1] <= grid[i][j]) ans = dfs(i, j+1, grid);
    if(!visited[i-1][j] && ans==0 && i-1>=0 && grid[i-1][j] <= grid[i][j]) ans = dfs(i-1, j, grid);
    if(!visited[i][j-1] && ans==0 && j-1>=0 && grid[i][j-1] <= grid[i][j]) ans = dfs(i, j-1, grid);
    if(ans==0) visited[i][j] = 0;
    return ans;
}

int main(){
    scanf("%d", &n);
    int maxh = 0;
    int grid[n][n]; 
    for(int i=0; i<n; i++) for(int j=0; j<n; j++){ 
        scanf("%d", grid[i]+j); 
        if(grid[i][j]>maxh) maxh = grid[i][j];
    }
    int pi = 0, pj = 0;
    int t = 0;
    for(t=0; t<maxh; t++){
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(grid[i][j]<t) grid[i][j] = t;
        for(int i=0; i<n; i++){ for(int j=0; j<n; j++) printf("%d ", grid[i][j]); printf("\n");}

        if(dfs(0, 0, grid)){
            printf("Ans: %d\n", t);
            return 0;
        }
        printf("\n\n");
    }
    printf("Ans: %d\n", t);
    return 0;
}