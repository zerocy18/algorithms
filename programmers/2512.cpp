#include <stdio.h>

int n;
int arr[10001];
int m;

int main()
{
    long long int right = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        if (arr[i] > right)
        {
            right = arr[i];
        }
    }
    scanf("%d", &m);
    long long int answer = 0;
    long long int left = 0;

    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        long long int tempSum = 0;
        //printf("mid : %d\n", mid);
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] < mid)
            {
                tempSum += arr[i];
            }
            else
            {
                tempSum += mid;
            }
        }
        if (tempSum <= m)
        {
            if (answer < mid)
            {
                answer = mid;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", budget[i]);
    // }
    printf("%lld", answer);
    return 0;
}
