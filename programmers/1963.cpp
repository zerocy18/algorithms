#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int prime[10000];
int T;
int sNum, eNum;
void setEratosthenes()
{
    for (int i = 2; i < 10000; i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i < 10000; i++)
    {
        if (prime[i] == 0)
            continue;

        for (int j = i + i; j < 10000; j += i)
        {
            prime[j] = 0;
        }
    }
}

bool isPrime(int number)
{
    if (prime[number] == 0)
        return false;
    else
        return true;
}

int bfs()
{
    queue<int> q;
    vector<bool> visit(10000, false);
    visit[sNum] = true;
    q.push(sNum);
    int cnt = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int cur = q.front();
            q.pop();

            if (cur == eNum)
            {
                return cnt;
            }
            int quo = cur / 10000;
            int div = cur % 1000;
            for (int i = 1000; i < 10000; i += 1000)
            {
                int next = quo * 10000 + i + div;
                if (isPrime(next) && !visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
            quo = cur / 1000;
            div = cur % 100;
            for (int i = 0; i < 1000; i += 100)
            {
                int next = quo * 1000 + i + div;
                if (isPrime(next) && !visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
            quo = cur / 100;
            div = cur % 10;
            for (int i = 0; i < 100; i += 10)
            {
                int next = quo * 100 + i + div;
                if (isPrime(next) && !visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
            quo = cur / 10;
            div = cur % 1;
            for (int i = 0; i < 10; i++)
            {
                int next = quo * 10 + i + div;
                if (isPrime(next) && !visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    scanf("%d", &T);
    setEratosthenes();
    while (T--)
    {
        scanf("%d %d", &sNum, &eNum);
        int res = bfs();
        if (res == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", res);
        }
    }
    return 0;
}
