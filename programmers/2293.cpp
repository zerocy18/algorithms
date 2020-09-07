#include <stdio.h>

int n, k;
int coins[100];
int dp[10001];

void input()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", coins + i);
    }
}

int main()
{
    input();
    dp[0] = 1;
    for (int i = coins[0]; i <= k; i = i + coins[0])
    {
        dp[i]++;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    printf("%d", dp[k]);
    return 0;
}
