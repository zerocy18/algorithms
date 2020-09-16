#include <stdio.h>
#include <queue>
#define G greater<int>
using namespace std;

priority_queue<int, vector<int>, G> pq;
int N;
int main()
{
    int answer = 0;
    int in;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        pq.push(in);
    }
    while (pq.size() != 1)
    {
        int ans = 0;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        ans = first + second;
        answer += first + second;
        pq.push(ans);
    }
    printf("%d", answer);
    return 0;
}
