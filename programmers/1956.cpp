#include <stdio.h>
#define INF 160000
int city[401][401];
int V, E;
void setInitial()
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            city[i][j] = INF;
        }
    }
}
void input()
{
    int a, b, c;
    scanf("%d %d", &V, &E);
    setInitial();
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        city[a][b] = c;
    }
}

void floyd()
{
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (city[i][j] > city[i][k] + city[k][j])
                {
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
    }
}

int solution()
{
    int answer = INF;
    for (int i = 1; i <= V; i++)
    {
        if (answer > city[i][i])
        {
            answer = city[i][i];
        }
    }
    return answer == INF ? -1 : answer;
}

int main()
{
    int ans;
    input();
    floyd();

    ans = solution();

    printf("%d", ans);
    return 0;
}
