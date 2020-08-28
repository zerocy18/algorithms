#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> v;

void input()
{
    int a;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        v.push_back(a);
    }
}

int calculate()
{
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += abs(v[i] - v[i + 1]);
    }
    return sum;
}

int main()
{
    int ans = -10000;
    input();
    sort(v.begin(), v.end());
    do
    {
        ans = max(ans, calculate());
    } while (next_permutation(v.begin(), v.end()));

    printf("%d", ans);
    return 0;
}
