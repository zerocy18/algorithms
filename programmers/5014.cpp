#include <stdio.h>
#include <queue>

using namespace std;
int F, S, G, U, D;
int visit[1000001];
queue<int> q;

int bfs(int n)
{
    int cnt = 1;
    q.push(n);
    visit[n] = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int now = q.front();
            q.pop();

            if (now == G)
            {
                return visit[now];
            }
            if (now + U <= F && visit[now + U] == -1)
            {
                q.push(now + U);
                visit[now + U] = cnt;
            }
            if (1 <= now - D && visit[now - D] == -1)
            {
                q.push(now - D);
                visit[now - D] = cnt;
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    for (int i = 0; i <= F; i++)
    {
        visit[i] = -1;
    }
    int ret = bfs(S);
    if (ret == -1)
    {
        printf("use the stairs");
    }
    else
        printf("%d", ret);
    return 0;
}
