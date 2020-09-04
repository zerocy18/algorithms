#include <stdio.h>
#define DIV 1000000000
int dp[10][101];
int n;

int main()
{
    long long answer = 0;
    scanf("%d", &n);
    dp[0][1] = 0;
    for (int i = 1; i < 10; i++)
    {
        dp[i][1] = 1;
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 0)
            {
                dp[i][k] += dp[i + 1][k - 1] % DIV;
            }
            else if (i == 9)
            {
                dp[i][k] += dp[i - 1][k - 1] % DIV;
            }
            else
            {
                dp[i][k] += (dp[i - 1][k - 1] + dp[i + 1][k - 1]) % DIV;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        answer += dp[i][n] % DIV;
    }
    answer %= DIV;
    printf("%lld", answer);
    return 0;
}
