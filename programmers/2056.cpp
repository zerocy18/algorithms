#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int hour[10001];
int cnt[10001];
int sum[10001];
vector<int> v[10001];

void input()
{
    int a;
    int b;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &hour[i], &a);
        for (int j = 0; j < a; j++)
        {
            scanf("%d", &b);
            v[i].push_back(b);
            cnt[b]++;
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
            sum[i] = hour[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            sum[next] = max(sum[next], sum[cur] + hour[next]);
            cnt[next]--;
            if (cnt[next] == 0)
            {
                q.push(next);
            }
        }
    }

    int answer = -1;
    for (int i = 1; i <= N; i++)
    {
        answer = max(answer, sum[i]);
    }
    printf("%d", answer);
    return 0;
}
