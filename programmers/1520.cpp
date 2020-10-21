#include <stdio.h>
int N, M;
int board[500][500];
int dp[500][500];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
            dp[i][j] = -1;
        }
    }
}
int dfs(int x, int y)
{
    //printf("%d %d\n", x, y);
    if (x == N - 1 && y == M - 1)
    {
        return 1;
    }
    if (dp[x][y] == -1)
    {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (board[nx][ny] < board[x][y])
                {
                    dp[x][y] += dfs(nx, ny);
                }
            }
        }
    }
    return dp[x][y];
}
int main()
{
    input();
    printf("%d", dfs(0, 0));
    return 0;
}
