#include <stdio.h>

int dp[1000001];
int min(int a, int b)
{
    return a > b ? b : a;
}
int main(void)
{
    int a;
    scanf("%d", &a);
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= a; i++)
    {
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        }
        else if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
        }
    }

    printf("%d", dp[a]);

    return 0;
}