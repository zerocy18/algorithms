#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int n, m;
queue<int> q;
vector<int> v[1001];
vector<int> countt(1001);
vector<int> answer;
int main()
{
    int num;
    int temp[1000];
    scanf("%d %d", &n, &m);
    while (m--)
    {
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &temp[i]);
        }
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                v[temp[i]].push_back(temp[j]);
                countt[temp[j]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (countt[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        int size = v[cur].size();
        for (int i = 0; i < size; i++)
        {
            countt[v[cur][i]]--;
            if (countt[v[cur][i]] == 0)
            {
                q.push(v[cur][i]);
            }
        }
    }
    if (answer.size() == n)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            printf("%d\n", answer[i]);
        }
    }
    else
    {
        printf("0");
    }
    return 0;
}
