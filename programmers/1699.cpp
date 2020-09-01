#include <stdio.h>
#include <vector>

using namespace std;

vector<int> square;
int dp[100001];

int min(int a, int b)
{
    return a < b ? a : b;
}
void calcSquare()
{
    for (int i = 1; i * i <= 100000; i++)
    {
        square.push_back(i * i);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
    }
    calcSquare();
    for (int i = 0; i < square.size(); i++)
    {
        for (int j = square[i]; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - square[i]] + 1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
