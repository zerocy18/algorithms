#include <stdio.h>
#include <queue>
#include <map>
#define P pair<int, int>
using namespace std;

int S;
queue<P> q; // first: screen , second : clip
map<P, int> cache;

int bfs(int screen, int clip)
{
    int cnt = 0;
    q.push(P(screen, clip));
    cache[P(screen, clip)]++;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            P now = q.front();
            if (now.first == S)
            {
                return cnt;
            }
            q.pop();
            if (cache[P(now.first, now.first)] == 0)
            {
                q.push(P(now.first, now.first));
                cache[P(now.first, now.first)]++;
            }
            if (now.second != 0 && cache[P(now.first + now.second, now.second)] == 0)
            {
                q.push(P(now.first + now.second, now.second));
                cache[P(now.first + now.second, now.second)]++;
            }
            if (now.first > 1 && cache[P(now.first - 1, now.second)] == 0)
            {
                q.push(P(now.first - 1, now.second));
                cache[P(now.first - 1, now.second)]++;
            }
        }
        cnt++;
    }
}

int main()
{
    scanf("%d", &S);
    int answer = bfs(1, 0);
    printf("%d", answer);
    return 0;
}
