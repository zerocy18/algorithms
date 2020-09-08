#include <stdio.h>
#include <vector>
#include <algorithm>
#define P pair<int, int>

using namespace std;

bool cmp(P a, P b)
{
    return a.first < b.first;
}

int T, N;

int main()
{
    int a, b;

    scanf("%d", &T);
    while (T--)
    {
        vector<P> v;
        int mx = 100001;
        int cnt = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &a, &b);
            v.push_back(P(a, b));
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            if (mx > v[i].second)
            {
                mx = v[i].second;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
