#include <stdio.h>
int H, W;
int arr[501];
int left = -1, right = -1;
int answer;
void input()
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < W; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < W; i++)
    {
        if (arr[i] != 0)
        {
            left = i;
            break;
        }
    }
    for (int i = W - 1; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            right = i;
            break;
        }
    }
}
int main()
{
    input();
    if (left == right)
    {
        printf("0");
        return 0;
    }
    while (left < right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] > arr[left + 1])
            {
                answer += arr[left] - arr[left + 1];
                arr[left + 1] = arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] > arr[right - 1])
            {
                answer += arr[right] - arr[right - 1];
                arr[right - 1] = arr[right];
            }
            right--;
        }
    }

    printf("%d", answer);
    return 0;
}
