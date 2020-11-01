#include <stdio.h>
int n;
int arr[1001];
int answer;
int first_index = 1010, last_index = -1;
void input()
{
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        arr[a] = b;
        if (a < first_index)
            first_index = a;
        if (a > last_index)
            last_index = a;
    }
}
int main()
{
    input();
    int left = first_index;
    int right = last_index;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            answer += arr[left];
            if (arr[left] > arr[left + 1])
            {
                arr[left + 1] = arr[left];
            }
            left++;
        }
        else
        {
            answer += arr[right];
            if (arr[right] > arr[right - 1])
            {
                arr[right - 1] = arr[right];
            }
            right--;
        }
    }
    printf("%d", answer);
    return 0;
}
