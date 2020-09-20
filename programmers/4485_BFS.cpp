#include <stdio.h>
#include <queue>
#define P pair<int, int>
#define INF 987654321

using namespace std;

int N;
int board[126][126];
int visit[126][126];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int answer = 0;

void setVisit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visit[i][j] = INF;
        }
    }
}
void input()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
}

void bfs(int i, int j)
{
    queue<P> q;
    q.push(P(i, j));
    visit[i][j] = board[i][j];
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N)
            {
                if (board[nx][ny] + visit[x][y] < visit[nx][ny])
                {
                    visit[nx][ny] = board[nx][ny] + visit[x][y];
                    q.push(P(nx, ny));
                }
            }
        }
    }
}

int main()
{
    int i = 1;

    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            break;
        }
        setVisit();
        input();
        bfs(0, 0);
        answer = visit[N - 1][N - 1];
        printf("Problem %d: %d\n", i, answer);
        answer = 0;
        i++;
    }
    return 0;
}
