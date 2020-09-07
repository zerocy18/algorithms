#include <stdio.h>
#define INF 2123456789
int n, k;
int coins[100];
int dp[10001];

int min(int a, int b)
{
    return a > b ? b : a;
}

void input()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", coins + i);
    }
}

void setDP()
{
    for (int i = 1; i <= k; i++)
    {
        dp[i] = INF;
    }
}

int main()
{
    input();
    setDP();

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if (dp[k] == INF)
    {
        printf("-1");
    }
    else
        printf("%d", dp[k]);
    return 0;
}
