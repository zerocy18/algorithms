#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> q;
bool visit[100001];
vector<int> v;
int answer;
int main()
{
    int time = 0;
    bool toggle = false;
    scanf("%d %d", &N, &K);
    q.push(N);
    while (!q.empty())
    {
        int size = q.size();
        //printf("%d 초 후 : ", time);
        for (int i = 0; i < size; i++)
        {
            int now = q.front();
            q.pop();
            visit[now] = true;
            //printf("%d ", now);
            if (now == K)
            {
                answer++;
                toggle = true;
            }
            if (now + 1 <= 100000 && !visit[now + 1])
            {
                q.push(now + 1);
            }
            if (0 <= now - 1 && !visit[now - 1])
            {
                q.push(now - 1);
            }
            if (2 * now <= 100000 && !visit[2 * now])
            {
                q.push(2 * now);
            }
        }
        //printf("\n");
        if (toggle)
        {
            break;
        }
        time++;
    }
    printf("%d\n%d", time, answer);
    return 0;
}
