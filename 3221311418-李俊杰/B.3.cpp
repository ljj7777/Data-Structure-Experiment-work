#include<stdio.h>
#define rows 5
#define cols 5
int maze[rows][cols];
int solution[rows][cols] = { 0 };
int findpath(int row, int col, int targetrow, int targetcol)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || maze[row][col] == 1)
    {
        return -1;
    }
    if (row == targetrow && col == targetcol)
    {
        solution[row][col] = 1;
        return 1;
    }
    maze[row][col] = 1;
    int up = findpath(row - 1, col, targetrow, targetcol);
    int down = findpath(row + 1, col, targetrow, targetcol);
    int left = findpath(row, col - 1, targetrow, targetcol);
    int right = findpath(row, col + 1, targetrow, targetcol);
    maze[row][col] = 0;
    if (up == -1 && down == -1 && left == -1 && right == -1)
    {
        return -1;
    }
    solution[row][col] = 1;
    int min = up;
    if (down != -1 && (min == -1 || down < min))
    {
        min = down;
    }
    if (left != -1 && (min == -1 || left < min))
    {
        min = left;
    }
    if (right != -1 && (min == -1 || right < min))
    {
        min = right;
    }
    return min + 1;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    int targetrow;
    int targetcol;
    scanf("%d %d", &targetrow, &targetcol);
    int slen = findpath(0, 0, targetrow, targetcol);
    if (slen == -1)
    {
        printf("无法到达目标位置！\n");
    }
    else
    {
        printf("最短路径长度为：%d\n", slen - 1);
    }
    return 0;
}