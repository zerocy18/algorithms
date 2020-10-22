#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int board[1000][1000];
int visit[1000][1000][2];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct NODE
{
    int x, y, drill;
} NODE;

void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }
}

int bfs()
{
    queue<NODE> q;
    q.push((NODE){0, 0, 1});
    visit[0][0][1] = 1;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int drill = q.front().drill;
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            return visit[x][y][drill];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (board[nx][ny] == 1 && drill == 1)
                {
                    visit[nx][ny][0] = visit[x][y][1] + 1;
                    q.push((NODE){nx, ny, 0});
                }
                if (board[nx][ny] == 0 && visit[nx][ny][drill] == 0)
                {
                    visit[nx][ny][drill] = visit[x][y][drill] + 1;
                    q.push((NODE){nx, ny, drill});
                }
            }
        }
    }

    return -1;
}

int main()
{
    input();
    printf("%d", bfs());
    return 0;
}
