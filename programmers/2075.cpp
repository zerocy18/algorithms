#include <stdio.h>
#include <queue>
#include <vector>
#define G greater<int>

using namespace std;
priority_queue<int, vector<int>, G> pq;

int main()
{
    int n;
    int in;
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", &in);
        if (pq.size() < n)
        {
            pq.push(in);
        }
        else
        {
            pq.push(in);
            pq.pop();
        }
    }
    printf("%d", pq.top());
    return 0;
}
