#include <stdio.h>
#include <vector>

using namespace std;
int N, M;
vector<int> relation[2000];
bool visit[2000];
int sum = 0;

void dfs(int num, int depth)
{
    if (depth == 5)
    {
        sum = 1;
        return;
    }
    visit[num] = true;

    for (int i = 0; i < relation[num].size(); i++)
    {
        if (!visit[relation[num][i]])
        {
            dfs(relation[num][i], depth + 1);
        }
    }
    visit[num] = false;
}

void setVisit()
{
    for (int i = 0; i < N; i++)
        visit[i] = false;
}

int main()
{
    int a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        setVisit();
        dfs(i, 1);
        if (sum == 1)
            break;
    }
    printf("%d", sum);

    return 0;
}
