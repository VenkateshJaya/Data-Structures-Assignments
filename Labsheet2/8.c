#include<stdio.h>
int g[1000][1000];
void dfs(int x, int y, int visited[], int nodes);
int main(){

    int nodes, edges;
    printf("Enter number of Vertices and Edges: ");
    scanf("%d %d",&nodes,&edges);
    int visited[1000];
    int i,j;
    int u,v;
    for(i = 0; i < nodes; i++)
    {
        for(j =0 ; j<nodes;j++){
            g[i][j] = 0;
        }
        visited[i] = 0;
    }
    visited[i] = -1;
    for(i = 0; i < edges; i++)
    {
        printf("Enter edge: ");
        scanf("%d %d", &u,&v);
        g[u-1][v-1] = 1;
        if(g[v-1][u-1] == 0)
            g[v-1][u-1] = -1;
    }

    int noQueries;
    printf("Enter number of Queries: ");
    scanf("%d",&noQueries);
    int x[100],y[100];
    i =0;
    while(noQueries -i > 0){
        printf("Enter Query: ");
        scanf("%d %d", &x[i],&y[i]);
        i++;
    }
    i =0;
    int flag;
    while(noQueries-i>0){
        visited[x[i]-1] = 1;
        dfs(x[i]-1,y[i]-1,visited,nodes);
        flag = checkConnected(x[i]-1,y[i]-1,visited,nodes);
        if(flag == 1){
            printf("Yes\n");
        }else
        {
            printf("No\n");
        }
        resetVisited(visited,nodes);
        i++;
    }
    return 0;
}

void dfs(int x, int y, int visited[], int nodes){
    if(x == y){
        return;
    }
    for(int i = 0; i < nodes; i++){
        if(!visited[i] && g[x][i] > 0){
            visited[i] = 1;
            dfs(i,y,visited,nodes);
        }
    }
    return;
}

int checkConnected(int x,int y,int visited[], int nodes){
    int i;
    int flag = 0;
    if(visited[x] == 1 && visited[y] == 1){
        flag = 1;
    }
    return flag;
}
void resetVisited(int visited[], int nodes){
    int i;
    for(i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }
    
}