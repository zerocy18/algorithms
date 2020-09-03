#include <stdio.h>

long long dp[2][91];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 0;
    for (int i = 3; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }
    printf("%lld", dp[0][n] + dp[1][n]);
    return 0;
}
