#include <stdio.h>

int n, m;
int root[1000001];

int getParent(int n)
{
    if (root[n] == n)
        return n;
    else
        return root[n] = getParent(root[n]);
}

void unionParent(int a, int b)
{
    int g1 = getParent(a);
    int g2 = getParent(b);
    if (g1 < g2)
        root[g2] = g1;
    else
        root[g1] = g2;
}

int find(int a, int b)
{
    int g1 = getParent(a);
    int g2 = getParent(b);
    if (g1 == g2)
        return 1;
    else
        return 0;
}

int main()
{
    int x, y, z;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        root[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if (x == 0)
        {
            unionParent(y, z);
        }
        else
        {
            if (find(y, z))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
