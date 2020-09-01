#include <stdio.h>
#include <queue>

#define P pair<int, int>

using namespace std;

bool visit[100001];
int N, K;
queue<P> q; // first : 위치, second: 시간

int main()
{
    int answer;
    scanf("%d %d", &N, &K);
    q.push(P(N, 0));
    visit[N] = true;
    while (!q.empty())
    {
        P now = q.front();
        q.pop();

        if (now.first == K)
        {
            answer = now.second;
            break;
        }
        if (2 * now.first <= 100000 && !visit[2 * now.first])
        {
            q.push(P(now.first * 2, now.second));
            visit[2 * now.first] = true;
        }
        if (0 <= now.first - 1 && !visit[now.first - 1])
        {
            q.push(P(now.first - 1, now.second + 1));
            visit[now.first - 1] = true;
        }
        if (now.first + 1 <= 100000 && !visit[now.first + 1])
        {
            q.push(P(now.first + 1, now.second + 1));
            visit[now.first + 1] = true;
        }
    }

    printf("%d", answer);
    return 0;
}
