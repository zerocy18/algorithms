#include <stdio.h>
#include <vector>
#define INF 1000000000
using namespace std;

int N;
vector<int> nums(11);
int plu, minu, multi, divi;
int mxv = -INF;
int mnv = INF;

void input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    scanf("%d %d %d %d", &plu, &minu, &multi, &divi);
}

void backtracking(int sum, int n, int pl, int mi, int mul, int div)
{
    if (n == N)
    {
        if (sum > mxv)
        {
            mxv = sum;
        }
        if (sum < mnv)
        {
            mnv = sum;
        }
        return;
    }
    if (pl < plu)
        backtracking(sum + nums[n], n + 1, pl + 1, mi, mul, div);
    if (mi < minu)
        backtracking(sum - nums[n], n + 1, pl, mi + 1, mul, div);
    if (mul < multi)
        backtracking(sum * nums[n], n + 1, pl, mi, mul + 1, div);
    if (div < divi)
        backtracking(sum / nums[n], n + 1, pl, mi, mul, div + 1);
}

int main()
{
    input();
    backtracking(nums[0], 1, 0, 0, 0, 0);
    printf("%d\n%d", mxv, mnv);
    return 0;
}
