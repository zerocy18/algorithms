#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 2123456789
using namespace std;
int N;
vector<int> liq;
int answer = INF;

int main()
{
    int in;
    int first, second;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        liq.push_back(in);
    }
    sort(liq.begin(), liq.end());
    int start = 0;
    int last = N - 1;
    while (start < last)
    {
        int sum = liq[start] + liq[last];
        if (abs(sum) < answer)
        {
            answer = abs(sum);
            first = liq[start];
            second = liq[last];
        }

        if (sum > 0)
        {
            last--;
        }
        else
        {
            start++;
        }
    }
    printf("%d %d", first, second);
    return 0;
}
