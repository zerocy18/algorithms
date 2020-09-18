#include <stdio.h>
#include <vector>
#define P pair<int, int>

using namespace std;

int V;
vector<P> tree[100001];
bool visit[100001];
int mxv = -1;
int endPoint;
void input()
{
    int a, b;
    scanf("%d", &V);
    for (int i = 1; i <= V; i++)
    {
        int j;
        scanf("%d", &j);
        while (1)
        {
            scanf("%d", &a);
            if (a == -1)
            {
                break;
            }
            else
            {
                scanf("%d", &b);
            }
            tree[j].push_back(P(a, b));
        }
    }
}

void setVisit()
{
    for (int i = 0; i <= V; i++)
    {
        visit[i] = false;
    }
}

void backtracking(int n, int sum)
{

    if (sum > mxv)
    {
        endPoint = n;
        mxv = sum;
    }
    visit[n] = true;
    for (int i = 0; i < tree[n].size(); i++)
    {
        if (!visit[tree[n][i].first])
        {
            backtracking(tree[n][i].first, sum + tree[n][i].second);
        }
    }
    visit[n] = false;
}

int main()
{
    input();

    backtracking(1, 0);
    setVisit();
    mxv = -1;
    backtracking(endPoint, 0);

    printf("%d", mxv);
    return 0;
}
