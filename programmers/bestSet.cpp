//vector push 시간복잡도...
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int mset[10000];
vector<int> solution(int n, int s)
{
    int total = 0;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        mset[i] = s / n;
        total += mset[i];
    }
    if (mset[0] == 0)
    {
        answer.push_back(-1);
        return answer;
    }
    if (total == s)
    {
        for (int i = 0; i < n; i++)
        {
            answer.push_back(mset[i]);
        }
    }
    else if (total < s)
    {
        int remain = s - total;
        for (int i = n - 1; i > n - 1 - remain; i--)
        {
            mset[i]++;
        }
        for (int i = 0; i < n; i++)
        {
            answer.push_back(mset[i]);
        }
    }
    else
    {
        int remain = total - s;
        for (int i = 0; i < remain; i++)
        {
            mset[i]--;
        }
        for (int i = 0; i < n; i++)
        {
            answer.push_back(mset[i]);
        }
    }
    return answer;
}
