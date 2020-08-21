// dp로 푸는 방식도 생각해볼것
#include <stdio.h>

int cnt;
int t, n;
void dfs(int sum, int one, int two, int three)
{
    //printf("%d %d %d %d\n", sum, one, two, three);
    if (sum > n)
    {
        return;
    }
    if (sum == n)
    {
        if (one > 0 || two > 0 || three > 0)
        {
            cnt++;
        }
        return;
    }

    dfs(sum + 1, one + 1, two, three);
    dfs(sum + 2, one, two + 1, three);
    dfs(sum + 3, one, two, three + 1);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cnt = 0;
        dfs(0, 0, 0, 0);
        printf("%d\n", cnt);
    }
    return 0;
}
