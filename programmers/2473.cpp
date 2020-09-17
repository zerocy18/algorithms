#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 3000000001

using namespace std;
vector<long long int> arr;
int N;
long long int mnv = INF;

int main()
{
    long long int a;
    int pi, st, ed;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N - 2; i++)
    {
        int pivot = i;
        int first = i + 1;
        int last = N - 1;

        while (first < last)
        {
            long long int sum = arr[first] + arr[last] + arr[pivot];
            if (abs(sum) < mnv)
            {
                mnv = abs(sum);
                pi = arr[pivot];
                st = arr[first];
                ed = arr[last];
            }
            if (sum > 0)
            {
                last--;
            }
            else
            {
                first++;
            }
        }
    }
    vector<int> ans;
    ans.push_back(pi);
    ans.push_back(st);
    ans.push_back(ed);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
