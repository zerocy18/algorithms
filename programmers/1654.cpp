#include <stdio.h>
#include <climits>
int K, N;
long long int lans[10001];

void input()
{
    scanf("%d %d", &K, &N);
    for (int i = 1; i <= K; i++)
    {
        scanf("%d", &lans[i]);
    }
}
int main()
{
    input();
    long long int answer = 0;
    long long int left = 0;
    long long int right = LLONG_MAX;

    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        long long int sum = 0;
        for (int i = 1; i <= K; i++)
        {
            sum += (lans[i] / mid);
        }
        if (sum < N)
        {
            right = mid - 1;
        }
        else
        {
            if (answer < mid)
            {
                answer = mid;
            }
            left = mid + 1;
        }
    }
    printf("%lld", answer);
    return 0;
}
