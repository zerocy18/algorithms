#include <stdio.h>

int n;
int graph[100][100];
void floyd()
{
    for (int k = 0; k < n; k++)
    { // k 거쳐가는 정점
        for (int i = 0; i < n; i++)
        { //i 시작 정점
            for (int j = 0; j < n; j++)
            { //j 종료 정점
                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                }
            }
        }
    }
}
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}
void result()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    input();
    floyd();
    result();
    return 0;
}
