// queue를 전역변수로 선언하였기 때문에
// 최단 거리 찍고 리턴 하면서 큐에 기존의 것들이 남아있으므로
// 다음 케이스 탐색의 경우 큐를 비워줘야함!

#include <stdio.h>
#include <queue>
#include <vector>
#define P pair<int, int>

using namespace std;

queue<P> q;
vector<int> v;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
bool visited[300][300];
int n;
int sx, sy;
int ex, ey;
int t;

int bfs(int x, int y)
{
    if (x == ex && y == ey)
    {
        return 0;
    }
    P cur;
    q.push(P(x, y));
    visited[x][y] = true;
    int cnt = 0;
    int nx, ny;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            cur = q.front();
            q.pop();
            if (cur.first == ex && cur.second == ey)
            {
                return cnt;
            }
            for (int i = 0; i < 8; i++)
            {
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n)
                {
                    if (!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push(P(nx, ny));
                    }
                }
            }
        }
        cnt++;
    }

    return cnt;
}

int main()
{

    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d", &n);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &ex, &ey);
        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                visited[i][j] = false;
            }
        }
        while (!q.empty())
            q.pop();
        v.push_back(bfs(sx, sy));

        //printf("\n\n sx:%d, sy:%d // ex:%d, ey:%d\n\n", sx, sy, ex, ey);
    }
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d\n", v[i]);
    }
    return 0;
}
