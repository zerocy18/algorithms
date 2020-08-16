#include <stdio.h>
#include <algorithm>
#define INF 2123456789

using namespace std;
int n, high = -INF, low = INF;
int area[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;
int maxSize = -INF;

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (area[nx][ny] > 0 && !visited[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &area[i][j]);
            if (high < area[i][j])
                high = area[i][j];
            if (low > area[i][j])
                low = area[i][j];
        }
    }
}
void setVisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}
int main()
{
    input();
    for (int rain = low; rain <= high; rain++)
    {
        setVisited();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rain > area[i][j])
                    area[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && area[i][j] > 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (maxSize < cnt)
        {
            maxSize = cnt;
        }
        cnt = 0;
    }
    printf("%d", maxSize);
    return 0;
}
