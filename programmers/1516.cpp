#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v[501];
vector<int> hour(501);
vector<int> cnt(501);
vector<int> res(501);
void input()
{
    int in;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &hour[i]);
        while (1)
        {
            scanf("%d", &in);
            if (in == -1)
                break;
            v[in].push_back(i);
            cnt[i]++;
        }
    }
}

int main()
{
    queue<int> q;

    input();
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
            res[i] = hour[i];
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            res[next] = max(res[next], res[cur] + hour[next]);
            cnt[next]--;
            if (cnt[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", res[i]);
    }
    return 0;
}
