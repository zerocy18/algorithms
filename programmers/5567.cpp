#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> link[501];
vector<int> visit(501, -1);
int cnt;
void input()
{
    int a, b;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
}
void bfs(int num)
{
    queue<int> q;
    int temp = 0;
    visit[num] = temp;
    q.push(num);

    while (!q.empty())
    {
        int qsize = q.size();

        temp++;
        if (temp > 2)
        {
            return;
        }
        for (int i = 0; i < qsize; i++)
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < link[cur].size(); j++)
            {
                int next = link[cur][j];
                if (visit[next] == -1)
                {
                    q.push(next);
                    visit[next] = temp;
                    cnt++;
                }
            }
        }
    }
}
int main()
{
    input();
    bfs(1);
    printf("%d", cnt);
    return 0;
}
