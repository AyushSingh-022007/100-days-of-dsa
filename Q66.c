#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool dfs(int node, int** graph, int* graphSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}
bool hasCycle(int V, int** graph, int* graphSize) {  
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphSize, visited, recStack))
                return true;
        }
    }
    return false;
}
int main() {
    int V = 4;
    int** graph = (int**)malloc(V * sizeof(int*));
    int graphSize[] = {1, 1, 1, 0};
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }
    graph[0][0] = 1;
    graph[1][0] = 2;
    graph[2][0] = 0;
    if (hasCycle(V, graph, graphSize))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}