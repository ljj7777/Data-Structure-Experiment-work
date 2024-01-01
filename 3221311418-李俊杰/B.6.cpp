#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define max_node 100
#define max_edge 100
struct Edge
{
    int qian;
    int hou;
    int weight;
};
void dfs(int curnode, int endNode, struct Edge edges[], bool visited[], int curpath, int* maxPath)
{
    if (curnode == endNode)
    {
        if (curpath > *maxPath)
        {
            *maxPath = curpath;
        }
        return;
    }
    visited[curnode] = true;
    for (int i = 0; i < max_edge; i++)
    {
        if (edges[i].qian == curnode && !visited[edges[i].hou])
        {
            dfs(edges[i].hou, endNode, edges, visited, curpath + edges[i].weight, maxPath);
        }
    }
    visited[curnode] = 0;
}
int fmpath(struct Edge edges[], int ecount, int startNode, int endNode)
{
    bool visited[max_node] = { 0 };
    int maxPath = INT_MIN;
    dfs(startNode, endNode, edges, visited, 0, &maxPath);
    return maxPath;
}
int main() {
    struct Edge edges[max_edge] =
    {
        {0, 1, 3},
        {0, 2, 8},
        {0, 4, 4},
        {1, 3, 1},
        {1, 4, 7},
        {2, 1, 4},
        {3, 0, 2},
        {3, 2, 5},
        {4, 3, 6}
    };
    int ecount = 9;
    int startNode = 3;
    int endNode = 4;
    int longestPath = fmpath(edges, ecount, startNode, endNode);
    printf("最长路径长度为：%d\n", longestPath);
    return 0;
}