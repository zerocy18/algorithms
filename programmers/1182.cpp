#include <stdio.h>

int N, S;
int num[20];
bool isUsed[20];
int cnt;

void backtracking(int sum, int n)
{
    if (n == N)
    {
        if (sum == S)
        {
            cnt++;
        }
        return;
    }
    if (!isUsed[n])
    {
        isUsed[n] = true;
        backtracking(sum + num[n], n + 1);

        isUsed[n] = false;
        backtracking(sum, n + 1);
    }
}

int main()
{
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", num + i);
    }
    backtracking(0, 0);
    if (S == 0)
        cnt--;
    printf("%d", cnt);
    return 0;
}
