#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> v;

int main()
{
    int in;
    int answer = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    int start = 0;
    int last = N - 1;
    while (start < last)
    {
        int sum = v[start] + v[last];
        if (sum == M)
        {
            answer++;
            start++;
            last--;
        }
        else
        {
            if (sum < M)
            {
                start++;
            }
            else
            {
                last--;
            }
        }
    }
    printf("%d", answer);
    return 0;
}
