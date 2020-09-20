#include <stdio.h>
#include <queue>
#include <vector>
#define P pair<int, int>
using namespace std;

vector<int> parent(100001, 0);
vector<int> visit(100001);
int N, K;
queue<P> q;
vector<int> res;

void bfs(int num)
{
    parent[num] = -1;
    visit[num] = 1;
    q.push(P(num, 0));
    while (!q.empty())
    {
        int nowPos = q.front().first;
        int nowTime = q.front().second;
        q.pop();
        if (nowPos == K)
        {
            printf("%d\n", nowTime);
            int idx = nowPos;
            while (idx != -1)
            {
                res.push_back(idx);
                idx = parent[idx];
            }
            for (int i = res.size() - 1; i >= 0; i--)
            {
                printf("%d ", res[i]);
            }
            return;
        }

        if (2 * nowPos <= 100000 && parent[2 * nowPos] == 0)
        {
            if (visit[2 * nowPos] == 0)
            {

                q.push(P(2 * nowPos, nowTime + 1));
                parent[2 * nowPos] = nowPos;
                visit[2 * nowPos] = 1;
            }
        }

        if (0 <= nowPos - 1 && parent[nowPos - 1] == 0)
        {
            if (visit[nowPos - 1] == 0)
            {
                q.push(P(nowPos - 1, nowTime + 1));
                parent[nowPos - 1] = nowPos;
                visit[nowPos - 1] = 1;
            }
        }

        if (nowPos + 1 <= 100000 && parent[nowPos + 1] == 0)
        {
            if (visit[nowPos + 1] == 0)
            {
                q.push(P(nowPos + 1, nowTime + 1));
                parent[nowPos + 1] = nowPos;
                visit[nowPos + 1] = 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    bfs(N);
    return 0;
}
