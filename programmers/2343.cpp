#include <stdio.h>
#include <stack>
#include <vector>
#define P pair<int, int>

using namespace std;

int main()
{
    int in;
    int N;
    vector<P> v(500001);
    stack<P> s;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &in);
        v[i] = P(in, i);
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     printf("%d %d\n", v[i].first, v[i].second);
    // }
    for (int i = 1; i <= N; i++)
    {
        if (s.empty())
        {
            s.push(v[i]);
            printf("0 ");
            continue;
        }
        if (v[i].first < s.top().first)
        {
            printf("%d ", s.top().second);
            s.push(v[i]);
        }
        else
        {
            while (v[i].first > s.top().first)
            {
                s.pop();
                if (s.empty())
                    break;
            }
            if (s.empty())
                printf("%d ", 0);
            else
                printf("%d ", s.top().second);
            s.push(v[i]);
        }
    }
    return 0;
}
