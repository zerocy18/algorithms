#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
using namespace std;

typedef struct STATUS
{
    int x, y, time;
} STATUS;

int N, M;
int lab[50][50];
vector<STATUS> virus, selected;
int answer = INF;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &lab[i][j]);
            if (lab[i][j] == 2)
            {
                virus.push_back((STATUS){i, j, 0});
            }
        }
    }
}

int spreadVirus()
{
    queue<STATUS> q;
    int emptyCount = 0;
    bool visit[50][50] = {
        false,
    };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lab[i][j] == 0)
                emptyCount++;

    for (int i = 0; i < selected.size(); i++)
    {
        q.push(selected[i]);
        visit[selected[i].x][selected[i].y] = true;
    }
    while (!q.empty())
    {
        STATUS cur = q.front();
        q.pop();
        if (lab[cur.x][cur.y] == 0)
        {
            emptyCount--;
        }
        if (emptyCount == 0)
        {
            return cur.time;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (0 <= nx && nx < N && 0 <= ny && ny < N)
            {
                if (!visit[nx][ny] && lab[nx][ny] != 1)
                {
                    visit[nx][ny] = true;
                    q.push((STATUS){nx, ny, cur.time + 1});
                }
            }
        }
    }
    return INF;
}

void dfsCombination(int num, int cnt)
{
    if (cnt == M)
    {
        int temp = spreadVirus();
        answer = min(answer, temp);
        return;
    }
    for (int i = num; i < virus.size(); i++)
    {
        selected.push_back(virus[i]);
        dfsCombination(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main(void)
{
    input();
    dfsCombination(0, 0);
    if (answer == INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", answer);
    }

    return 0;
}
