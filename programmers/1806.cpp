#include <stdio.h>

int n, s;
long long int presum[100001];
int minlen = 100001;

int main()
{
    int input;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        presum[i] = presum[i - 1] + input;
    }
    int start = 0;
    int end = 0;
    while (start <= n && end <= n)
    {
        if (s <= presum[end] - presum[start])
        {
            if (minlen > end - start)
                minlen = end - start;
            start++;
        }
        else
        {
            end++;
        }
    }
    if (minlen == 100001)
        minlen = 0;

    printf("%d\n", minlen);
    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%d ", presum[i]);
    // }
    return 0;
}
