#include <stdio.h>
#include <vector>
#define P pair<int, int>

using namespace std;

vector<P> tree[10001]; // first : node, second : weight
bool visit[10001];
int n;
int mxv = -1;

void input()
{
    int a, b, c;

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back(P(b, c));
        tree[b].push_back(P(a, c));
    }
}

void backtracking(int n, int sum)
{
    visit[n] = true;
    if (mxv < sum)
    {
        mxv = sum;
        // printf("%d\n", mxv);
    }
    for (int i = 0; i < tree[n].size(); i++)
    {
        if (!visit[tree[n][i].first])
        {
            backtracking(tree[n][i].first, sum + tree[n][i].second);
            visit[tree[n][i].first] = false;
        }
    }
}

void setVisit()
{
    for (int i = 0; i <= n; i++)
    {
        visit[i] = false;
    }
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        setVisit();
        backtracking(i, 0);
    }
    printf("%d", mxv);
    return 0;
}
