#include <stdio.h>

int n, m;
int presum[100001];
int main()
{
    int in;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in);
        presum[i] = presum[i - 1] + in;
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%d ", presum[i]);
    // }
    while (m--)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", presum[end] - presum[start - 1]);
    }
    return 0;
}
