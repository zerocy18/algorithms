#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define P pair<int, int>
#define INF 0x7fffffff

using namespace std;

int N;
int board[20][20];
int sharkX, sharkY;
int sharkSize = 2;
int eatCount = 0;
int answer;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

typedef struct FOOD
{
    int x, y, dist;
} FOOD;

vector<FOOD> eat;

bool compare(FOOD a, FOOD b)
{
    if (a.dist == b.dist)
    {
        if (a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return a.dist < b.dist;
}

void input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9)
            {
                board[i][j] = 0;
                sharkX = i, sharkY = j;
            }
        }
    }
}

void bfs(int i, int j)
{
    eat.clear();
    queue<P> q;
    q.push(P(i, j));
    int eatDist = INF;
    int visit[20][20] = {
        0,
    };
    while (!q.empty())
    {
        P cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (0 <= nx && nx < N && 0 <= ny && ny < N)
            {
                if (visit[nx][ny] == 0 && board[nx][ny] <= sharkSize)
                {
                    visit[nx][ny] = visit[cur.first][cur.second] + 1;
                    if (0 < board[nx][ny] && board[nx][ny] < sharkSize)
                    {
                        //꺼ㅓㅓㅓㅓㅓ억
                        if (eatDist >= visit[nx][ny])
                        {
                            eatDist = visit[nx][ny];
                            eat.push_back((FOOD){nx, ny, eatDist});
                        }
                    }
                    //이동만
                    q.push(P(nx, ny));
                }
            }
        }
    }
}

int main()
{
    input();
    while (1)
    {
        bfs(sharkX, sharkY);

        if (eat.empty())
        {
            break;
        }
        else
        {
            sort(eat.begin(), eat.end(), compare);
            eatCount++;
            answer += eat[0].dist;
            board[eat[0].x][eat[0].y] = 0;
            sharkX = eat[0].x;
            sharkY = eat[0].y;
            if (sharkSize == eatCount)
            {
                sharkSize++;
                eatCount = 0;
            }
        }
    }
    printf("%d", answer);
    return 0;
}
