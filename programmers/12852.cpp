#include <stdio.h>
#include <queue>

using namespace std;

int parent[1000001];
queue<int> q;
vector<int> res;
int main()
{
    int x;
    int time = 0;
    scanf("%d", &x);
    q.push(x);
    parent[x] = -1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int now = q.front();

            q.pop();
            if (now == 1)
            {
                // for (int i = 1; i <= x; i++)
                // {
                //     printf("%d ", parent[i]);
                // }
                printf("%d\n", time);
                int idx = now;
                while (idx != x)
                {
                    res.push_back(idx);
                    idx = parent[idx];
                }
                res.push_back(x);
                for (int i = res.size() - 1; i >= 0; i--)
                {
                    printf("%d ", res[i]);
                }
                return 0;
            }
            if (now % 3 == 0 && parent[now / 3] == 0)
            {
                parent[now / 3] = now;
                q.push(now / 3);
            }
            if (now % 2 == 0 && parent[now / 2] == 0)
            {
                parent[now / 2] = now;
                q.push(now / 2);
            }
            if (0 <= now - 1 && parent[now - 1] == 0)
            {
                parent[now - 1] = now;
                q.push(now - 1);
            }
        }
        time++;
    }
    return 0;
}
