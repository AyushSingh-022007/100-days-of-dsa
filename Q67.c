#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;
void dfs(int u) {
    visited[u] = 1;
    for(int v = 0; v < n; v++) {
        if(graph[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
    stack[++top] = u;
}
void topoSort() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}
int main() {
    int e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }
    topoSort();
    return 0;
}