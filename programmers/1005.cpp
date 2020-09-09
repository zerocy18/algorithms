#include <stdio.h>
#include <vector>
#include <queue>

#define INF 2123456789

using namespace std;

int N, K;
int cost[1001];
int cnt[1001];
int dp[1001];
int dest;
queue<int> q;
vector<int> v[1001];

int max(int a, int b)
{
    return a > b ? a : b;
}
void input()
{
    int a, b;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        cnt[b]++;
    }
    scanf("%d", &dest);
}
void setting()
{
    for (int i = 0; i < 1001; i++)
    {
        cost[i] = 0;
        cnt[i] = 0;
        dp[i] = 0;
        v[i].clear();
    }
}
int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        input();
        for (int i = 1; i <= N; i++)
        {
            if (cnt[i] == 0)
            {
                q.push(i);
                dp[i] = cost[i];
            }
        }
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < v[now].size(); i++)
            {
                int next = v[now][i];
                dp[next] = max(dp[now] + cost[next], dp[next]);
                cnt[next]--;
                if (cnt[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        printf("%d\n", dp[dest]);
        setting();
    }
    return 0;
}
