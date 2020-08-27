#include <stdio.h>
int n, m;
int miro[1001][1001];
int dp[1001][1001];
int max(int a, int b)
{
    return a > b ? a : b;
}
void input()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &miro[i][j]);
        }
    }
}
int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + miro[i][j], max(dp[i][j - 1] + miro[i][j], dp[i - 1][j] + miro[i][j]));
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
