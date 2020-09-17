#include <stdio.h>
#define INF 2123456789
int myAbs(int a)
{
    return a > 0 ? a : -a;
}

int N;
int arr[100000];

int main()
{
    int min = INF;
    int st, ed;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }
    int first = 0;
    int last = N - 1;
    while (first < last)
    {
        if (myAbs(arr[last] + arr[first]) < min)
        {
            min = myAbs(arr[last] + arr[first]);
            st = arr[first];
            ed = arr[last];
        }

        if (arr[last] + arr[first] > 0)
        {
            last--;
        }
        else
        {
            first++;
        }
    }
    printf("%d %d", st, ed);
    return 0;
}
