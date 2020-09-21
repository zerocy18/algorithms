#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int K, V, E;
vector<int> link[20001];
vector<int> visit(20001, 0);
void dfs(int x, int color)
{
    visit[x] = color;
    for (int i = 0; i < link[x].size(); i++)
    {
        int nx = link[x][i];
        if (visit[nx] == 0)
        {
            dfs(nx, 3 - color);
        }
    }
}

bool check()
{
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j < link[i].size(); j++)
        {
            int next = link[i][j];
            if (visit[next] == visit[i])
                return false;
        }
    }
    return true;
}
void setting()
{
    for (int i = 0; i <= V; i++)
    {
        visit[i] = 0;
        link[i].clear();
    }
}
int main()
{
    int a, b;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d", &a, &b);
            link[a].push_back(b);
            link[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
        {
            if (visit[i] == 0)
            {
                dfs(i, 1);
            }
        }
        if (check())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        setting();
    }
    return 0;
}
