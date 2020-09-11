#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int root[100001];

typedef struct node
{
    int st, en, weight;
} node;
vector<node> v;
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
    {
        return 0;
    }
}

void unionParent(int x, int y)
{
    int x_root = getParent(x);
    int y_root = getParent(y);

    if (x_root < y_root)
    {
        root[y_root] = x_root;
    }
    else
    {
        root[x_root] = y_root;
    }
}

int main()
{
    int a, b, c;
    int sum=0, last;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }
    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back((node){a, b, c});
    }
    sort(v.begin(), v.end(), comp);
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!finding(v[i].st, v[i].en))
        {
            cnt++;
            sum += v[i].weight;
            unionParent(v[i].st, v[i].en);
            if (cnt == n - 2)
                break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
