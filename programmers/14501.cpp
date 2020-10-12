#include <stdio.h>
int N;
int T[16], P[16];
int sum[16];
int max = -1;
void input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", T + i, P + i);
    }
}

void func(int price, int cnt)
{
    if (cnt > N + 1)
    {
        return;
    }
    if (max < price)
        max = price;
    for (int i = cnt; i <= N; i++)
    {
        func(price + P[i], i + T[i]);
    }
}
int main()
{
    input();
    func(0, 1);
    printf("%d", max);
    return 0;
}
