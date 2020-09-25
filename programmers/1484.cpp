#include <stdio.h>
int main()
{
    int G;
    int answer = 0;
    scanf("%d", &G);
    long long i = 1;
    long long j = 1;
    while (1)
    {
        long long ans = j * j - i * i;
        if (G >= ans)
        {
            if (G == ans)
            {
                //printf("%d %d\n", j, i);
                printf("%lld\n", j);
                answer++;
            }
            j++;
        }
        else
        {
            i++;
        }
        if (ans > 1000000)
            break;
    }
    if (answer == 0)
        printf("-1");

    return 0;
}
