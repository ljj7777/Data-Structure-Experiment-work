#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 5
void printPath(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}
void findAllPaths(int graph[MAX_NODES][MAX_NODES], int start, int end, bool visited[], int path[], int pathLen)
{
    visited[start] = true;
    path[pathLen] = start;
    pathLen++;
    if (start == end)
    {
        printf("找到一条路径：");
        printPath(path, pathLen);
    }
    else
    {
        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph[start][i] && !visited[i])
            {
                findAllPaths(graph, i, end, visited, path, pathLen);
            }
        }
    }
    visited[start] = false;
}
int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    bool visited[MAX_NODES];
    int path[MAX_NODES];
    int pathLen = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            if (i != j && graph[i][j]) {
                printf("从顶点 %d 到顶点 %d 的所有路径：\n", i, j);
                for (int k = 0; k < MAX_NODES; k++) {
                    visited[k] = false;
                }
                findAllPaths(graph, i, j, visited, path, pathLen);
            }
        }
    }
    return 0;
}