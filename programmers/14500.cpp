//ㅗㅜㅏㅓ도형 빼고 DFS로 풀어내고
// ㅗㅜㅏㅓ도형을 구하는 함수만 따로 잡아주면 풀리는 문제였다...
#include <stdio.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int paper[500][500];
bool visited[500][500];
int answer = -1;

int max(int a, int b)
{
    return a > b ? a : b;
}

void input()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
}

void dfs(int x, int y, int sum, int cnt)
{

    if (cnt == 3)
    {
        answer = max(sum, answer);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (!visited[nx][ny])
            {
                visited[x][y] = true;
                dfs(nx, ny, sum + paper[nx][ny], cnt + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

void exceptionShape(int x, int y) // ㅗㅜㅏㅓ (x,y)가 중심으로 체크
{
    if (0 <= x - 1 && x < n && 0 <= y - 1 && y + 1 < m) // Shape ㅗ
    {
        int temp = paper[x][y] + paper[x - 1][y] + paper[x][y - 1] + paper[x][y + 1];
        answer = max(temp, answer);
    }
    if (0 <= x && x + 1 < n && 0 <= y - 1 && y + 1 < m) // Shape ㅜ
    {
        int temp = paper[x][y] + paper[x + 1][y] + paper[x][y - 1] + paper[x][y + 1];
        answer = max(temp, answer);
    }
    if (0 <= x - 1 && x + 1 < n && 0 <= y && y + 1 < m) // Shape ㅏ
    {
        int temp = paper[x][y] + paper[x - 1][y] + paper[x + 1][y] + paper[x][y + 1];
        answer = max(temp, answer);
    }
    if (0 <= x - 1 && x + 1 < n && 0 <= y - 1 && y < m) // Shape ㅓ
    {
        int temp = paper[x][y] + paper[x - 1][y] + paper[x + 1][y] + paper[x][y - 1];
        answer = max(temp, answer);
    }
}

int main()
{
    input();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(i, j, paper[i][j], 0);
            exceptionShape(i, j);
            visited[i][j] = false;
        }
    }
    printf("%d\n", answer);
    return 0;
}
