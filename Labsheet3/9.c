#include<stdio.h>
int g[1000][1000];
void dfs(int x, int visited[], int n);
int checkConnected(int visited[], int nodes);
void resetVisited(int visited[], int nodes);
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
    int flag;// if the current vertex connects to the rest of the vertices
    int anyflag;// if any of the vertices connect to the rest
    int yes[1000];
    j=0;
    for(i = 0; i < nodes; i++)
    {
        visited[i] = 1;
        // printf("%d ",i);
        dfs(i,visited,nodes);
        flag = checkConnected(visited,nodes);
        
        if(flag == 1){
            anyflag = 1;
            yes[j++] = i;
        }
        resetVisited(visited,nodes);
        // visited[i] = 0;
    }
    yes[j] = -1;
    i = 0;
    if(anyflag == 1){
        printf("Yes");
        while(yes[i]!=-1){
            printf(", %d",yes[i]+1);
            i++;
        }
        
    }else
    {
        printf("No");
    }
    

    return 0;
}

void dfs(int x, int visited[], int nodes){
    for(int i = 0; i < nodes; i++){
        if(!visited[i] && g[x][i] > 0){
            // printf("%d ",i);
            visited[i] = 1;
            dfs(i,visited,nodes);
        }
    }
}

int checkConnected(int visited[], int nodes){
    int i;
    int flag = 1;
    for(i = 0; i < nodes; i++)
    {
        if(visited[i]==0)
            flag = 0;
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