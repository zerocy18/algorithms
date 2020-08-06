#include <stdio.h>
#include <queue>
#define V vector<int>

using namespace std;

int abs(int x)
{
    return x > 0 ? x : -x;
}

struct compare
{
    bool operator()(int x, int y)
    {
        if (abs(x) == abs(y))
            return x > y;
        else
        {
            return abs(x) > abs(y);
        }
    }
};

priority_queue<int, V, compare> pq;
int main()
{
    int n;
    int k;
    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &k);
        if (k == 0)
        {
            if (!pq.empty())
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            pq.push(k);
        }
    }
    return 0;
}
