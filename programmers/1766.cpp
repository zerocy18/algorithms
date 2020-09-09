#include <stdio.h>
#include <queue>
#include <vector>
#define G greater<int>
using namespace std;

int N, M;
vector<int> v[32001];
priority_queue<int, vector<int>, G> pq;
queue<int> q;
vector<int> answer;
int cnt[32001];

void input()
{
    int a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        cnt[b]++;
    }
}

int main()
{
    input();
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        answer.push_back(now);
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            cnt[next]--;
            if (cnt[next] == 0)
            {
                pq.push(next);
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}
