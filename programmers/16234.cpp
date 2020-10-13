#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define P pair<int, int>
using namespace std;
int N, L, R;
int board[50][50];
bool visit[50][50];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool checked = false;
int answer = 0;

void input()
{
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
}

void bfs(int x, int y)
{
    queue<P> q;
    queue<P> unionCountry;
    int sum = 0;

    visit[x][y] = true;

    q.push(P(x, y));
    unionCountry.push(P(x, y));
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        sum += board[curX][curY];
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
            {
                if (!visit[nextX][nextY])
                {
                    int diff = abs(board[nextX][nextY] - board[curX][curY]);
                    if (L <= diff && diff <= R)
                    {
                        q.push(P(nextX, nextY));
                        checked = true;
                        visit[nextX][nextY] = true;
                        unionCountry.push(P(nextX, nextY));
                    }
                }
            }
        }
    }

    int avg = sum / unionCountry.size();
    while (!unionCountry.empty())
    {
        P cur = unionCountry.front();
        unionCountry.pop();
        board[cur.first][cur.second] = avg;
    }
}
void setVisit()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visit[i][j] = false;
}
int main()
{
    input();
    while (1)
    {
        checked = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visit[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        setVisit();
        if (!checked)
            break;
        answer++;
    }

    printf("%d\n", answer);
    return 0;
}
