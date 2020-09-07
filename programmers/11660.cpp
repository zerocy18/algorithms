#include <stdio.h>

int N, M;
int arr[1025][1025];
int sum[1025][1025];

void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }
}

int main()
{
    input();
    while (M--)
    {
        int answer = 0;
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int x = x1; x <= x2; x++)
        {
            answer += sum[x][y2] - sum[x][y1 - 1];
        }
        printf("%d\n", answer);
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         printf("%d ", sum[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
