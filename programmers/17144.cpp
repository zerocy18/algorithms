#include <stdio.h>
#include <queue>
#include <vector>
#define P pair<int, int>

using namespace std;

typedef struct dust
{
    int x;
    int y;
    int weight;
} dust;

int R, C, T;
int room[50][50];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
vector<P> clean;

void input()
{
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &room[i][j]);
            if (room[i][j] == -1)
            {
                clean.push_back(P(i, j));
            }
        }
    }
}

void flood()
{
    int near = 0;
    queue<dust> q;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] > 4)
            {
                q.push((dust){i, j, room[i][j]});
            }
        }
    }

    while (!q.empty())
    {
        int n = 0;
        int x = q.front().x;
        int y = q.front().y;
        int weight = q.front().weight;
        int near = weight / 5;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < R && 0 <= ny && ny < C)
            {
                if (room[nx][ny] != -1)
                {
                    n++;
                    room[nx][ny] += near;
                }
            }
        }
        room[x][y] -= near * n;
    }
}

void upClean()
{
    int x = clean[0].first;
    int y = clean[0].second;
    for (int i = x - 2; i >= 0; i--)
    {
        room[i + 1][y] = room[i][y];
    }
    for (int j = 1; j < C; j++)
    {
        room[0][j - 1] = room[0][j];
    }
    for (int i = 1; i <= x; i++)
    {
        room[i - 1][C - 1] = room[i][C - 1];
    }
    for (int j = C - 2; j > 0; j--)
    {
        room[x][j + 1] = room[x][j];
    }
    room[x][1] = 0;
}

void downClean()
{
    int x = clean[1].first;
    int y = clean[1].second;

    for (int i = x + 2; i < R; i++)
    {
        room[i - 1][y] = room[i][y];
    }
    for (int j = 1; j < C; j++)
    {
        room[R - 1][j - 1] = room[R - 1][j];
    }
    for (int i = R - 2; i >= x; i--)
    {
        room[i + 1][C - 1] = room[i][C - 1];
    }
    for (int j = C - 2; j > 0; j--)
    {
        room[x][j + 1] = room[x][j];
    }
    room[x][1] = 0;
}

int printDust()
{
    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] > 0)
            {
                answer += room[i][j];
            }
        }
    }
    return answer;
}

int main()
{
    input();
    for (int i = 0; i < T; i++)
    {
        flood();
        upClean();
        downClean();
    }
    printf("%d", printDust());
    return 0;
}
