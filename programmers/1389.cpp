#include <stdio.h>
#define INF 100001
int N, M;
int graph[101][101];

void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    int a, b;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int solution()
{
    int saveidx;
    int minvalue = INF;
    for (int idx = 1; idx <= N; idx++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += graph[idx][j];
        }
        if (minvalue > sum)
        {
            minvalue = sum;
            saveidx = idx;
        }
    }
    return saveidx;
}

int main()
{
    input();
    floyd();
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", solution());
    return 0;
}
