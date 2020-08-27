#include <stdio.h>
#define N 10001
int TC;
int n;
int arr[N];
void gold(int k)
{
    int mid = k / 2;
    for (int i = mid; i > 0; i--)
    {
        if (arr[i] != 0 && arr[k - i] != 0)
        {
            printf("%d %d\n", i, k - i);
            return;
        }
    }
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        arr[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = i + i; j < N; j += i)
        {
            arr[j] = 0;
        }
    }

    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d", &n);
        gold(n);
    }
    return 0;
}
