#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int root[10001];
int v, e;
int res;

typedef struct node
{
    int st;
    int en;
    int weight;
} node;
vector<node> vv;
bool comp(node a, node b)
{
    return a.weight < b.weight;
}

int getParent(int x)
{
    if (x == root[x])
        return x;
    else
        return root[x] = getParent(root[x]);
}

int finding(int x, int y)
{
    int x_root = getParent(x);
    int y_root = getParent(y);
    if (x_root == y_root)
        return 1;
    else
        return 0;
}

void unionParent(int x, int y)
{
    int x_root = getParent(x);
    int y_root = getParent(y);
    if (x_root < y_root)
        root[y_root] = x_root;
    else
        root[x_root] = y_root;
}

int main()
{
    int a, b, c;
    int answer = 0;
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++)
    {
        root[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        vv.push_back((node){a, b, c});
    }
    sort(vv.begin(), vv.end(), comp);
    for (int i = 0; i < vv.size(); i++)
    {
        if (!finding(vv[i].st, vv[i].en))
        {
            unionParent(vv[i].st, vv[i].en);
            answer += vv[i].weight;
        }
    }
    printf("%d", answer);
    return 0;
}
