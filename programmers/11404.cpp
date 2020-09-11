#include <stdio.h>
#define INF 9900001
int n, m;
int a, b, c;
int bus[101][101];

void input()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                bus[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (bus[a][b] > c)
        {
            bus[a][b] = c;
        }
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
                if (bus[i][j] > bus[i][k] + bus[k][j])
                {
                    bus[i][j] = bus[i][k] + bus[k][j];
                }
            }
        }
    }
}

void show()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (bus[i][j] == INF)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", bus[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    input();
    floyd();
    show();
    return 0;
}
