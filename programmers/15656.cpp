#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> ans;
int check[8];
int N, M;

void input()
{
    int a;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
}

void backtracking(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (check[i] < M)
        {
            check[i]++;
            ans.push_back(nums[i]);
            backtracking(cnt + 1);
            ans.pop_back();
            check[i]--;
        }
    }
}

int main()
{
    input();
    backtracking(0);
    return 0;
}
