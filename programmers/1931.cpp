#include <stdio.h>
#include <vector>
#include <algorithm>

#define P pair<int, int>

using namespace std;
int N;
vector<P> v;
void input()
{
    int a, b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back(P(a, b));
    }
    sort(v.begin(), v.end());
}
int main()
{
    int answer = 1;
    int endtime = (1 << 31) - 1;
    input();
    //printf("%d", endtime);
    for (int i = 0; i < v.size(); i++)
    {
        int st = v[i].first;
        int ed = v[i].second;
        if (st >= endtime)
        {
            answer++;
            endtime = ed;
        }
        if (ed < endtime)
            endtime = ed;

        //        printf("%d ", endtime);
    }
    printf("%d", answer);
    return 0;
}
