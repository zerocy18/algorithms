#include <stdio.h>
#include <queue>
#define P pair<int, int>

using namespace std;
queue<P> q;
bool visit[50][50];
char area[50][51];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int N, M; //N:세로 , M:가로
int answer = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", area[i]);
    }
}
void setVisit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visit[i][j] = false;
        }
    }
}

int bfs(int x, int y)
{
    q.push(P(x, y));
    visit[x][y] = true;
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            P cur = q.front();
            q.pop();
            // printf("time: %d  / %d %d\n", time, cur.first, cur.second);
            for (int j = 0; j < 4; j++)
            {
                int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];

                if (0 <= nx && nx < N && 0 <= ny && ny < M)
                {
                    if (!visit[nx][ny] && area[nx][ny] == 'L')
                    {
                        q.push(P(nx, ny));
                        visit[nx][ny] = true;
                    }
                }
            }
        }
        time++;
    }
    return time - 1;
}
int main()
{
    input();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (area[i][j] == 'L')
            {
                answer = max(answer, bfs(i, j));
                setVisit();
            }
        }
    }
    printf("%d", answer);

    //printf("%d", bfs(4, 1));
    return 0;
}
