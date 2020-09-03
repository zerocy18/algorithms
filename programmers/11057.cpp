#include <stdio.h>

long long int dp[10][1001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            long long int sum = 0;
            for (int k = j; k < 10; k++)
            {
                sum += (dp[k][i - 1]) % 10007;
            }
            dp[j][i] = sum % 10007;
        }
    }

    long long int answer = 0;

    for (int i = 0; i < 10; i++)
    {
        answer += dp[i][n] % 10007;
    }
    printf("%lld", answer % 10007);
    return 0;
}
