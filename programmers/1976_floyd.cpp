#include <stdio.h>
int N, M;
int cities[201][201];
int route[1000];

void input()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &cities[i][j]);
    for (int i = 0; i < M; i++)
        scanf("%d", route + i);
}

void floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (cities[i][k] == 1 && cities[k][j] == 1)
                {
                    cities[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cities[i][i] = 1;
    }
}
int solution()
{
    for (int i = 0; i < M - 1; i++)
    {
        if (cities[route[i]][route[i + 1]] == 0)
            return -1;
    }
    return 1;
}
int main()
{
    int answer = -1;
    input();
    floyd();
    answer = solution();
    if (answer == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
