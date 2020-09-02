//R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고 물이 차있는 지역은 '*',
//돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.
#include <stdio.h>
#include <queue>
#include <vector>
#define P pair<int, int>

using namespace std;
int R, C;
char forest[50][51];
bool visitWater[50][50];
bool visit[50][50];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void input()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        scanf("%s", forest[i]);
    }
}

void fillWater() //물이 한칸 번지는 것 구현
{
    queue<P> water;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (forest[i][j] == '*' && !visitWater[i][j])
            {
                water.push(P(i, j));
            }
        }
    }

    int size = water.size();
    for (int i = 0; i < size; i++)
    {
        P now = water.front();
        water.pop();
        visitWater[now.first][now.second] = true;
        for (int j = 0; j < 4; j++)
        {
            int nx = now.first + dx[j];
            int ny = now.second + dy[j];
            if (0 <= nx && nx < R && 0 <= ny && ny < C)
            {
                if (!visitWater[nx][ny] && forest[nx][ny] == '.')
                {
                    forest[nx][ny] = '*';
                }
            }
        }
    }
}

void printMap()
{
    printf("_________________\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%c", forest[i][j]);
        }
        printf("\n");
    }
}

int hedgehog(int x, int y, int destX, int destY)
{
    queue<P> q;
    visit[x][y] = true;
    q.push(P(x, y));
    int cnt = 0;
    while (!q.empty())
    {
        fillWater();
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            P now = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = now.first + dx[j];
                int ny = now.second + dy[j];
                if (nx == destX && ny == destY)
                {
                    return cnt + 1;
                }
                if (0 <= nx && nx < R && 0 <= ny && ny < C)
                {
                    if (!visit[nx][ny] && forest[nx][ny] == '.')
                    {
                        visit[nx][ny] = true;
                        q.push(P(nx, ny));
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    vector<P> pos(2);
    input();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (forest[i][j] == 'D')
            {
                pos[0] = P(i, j);
            }
            if (forest[i][j] == 'S')
            {
                pos[1] = P(i, j);
            }
        }
    }
    //printf("%d %d %d %d", pos[1].first, pos[1].second, pos[0].first, pos[0].second);
    int answer = hedgehog(pos[1].first, pos[1].second, pos[0].first, pos[0].second);
    if (answer == -1)
    {
        printf("KAKTUS");
    }
    else
    {
        printf("%d", answer);
    }
    return 0;
}
