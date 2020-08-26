#include <stdio.h>
int n, m;
int graph[501][501];

void input()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                }
            }
        }
    }
}
int main()
{
    int answer = 0;
    input();
    floyd();

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == 1 || graph[j][i] == 1)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    printf("%d", answer);
    return 0;
}
