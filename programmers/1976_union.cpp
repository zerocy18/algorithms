#include <stdio.h>
int N, M;
int cities[201][201];
int route[1000];
int root[201];

void setRoot()
{
    for (int i = 0; i <= N; i++)
        root[i] = i;
}

int getParent(int x)
{
    if (x == root[x])
        return x;
    else
        return root[x] = getParent(root[x]);
}

void unionParent(int x, int y)
{
    int root_x = getParent(x);
    int root_y = getParent(y);

    if (root_x < root_y)
    {
        root[root_y] = root_x;
    }
    else
    {
        root[root_x] = root_y;
    }
}

int find(int x, int y)
{
    int rootX = getParent(x);
    int rootY = getParent(y);

    if (rootX == rootY)
        return 1;
    else
        return 0;
}
void input()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &cities[i][j]);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", route + i);
    }
}

void linkNode()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (cities[i][j] == 1)
            {
                unionParent(i, j);
            }
        }
    }
}

int solution()
{
    for (int i = 0; i < M - 1; i++)
    {
        if (!find(route[i], route[i + 1]))
        {
            return -1;
        }
    }
    return 1;
}

int main()
{
    int answer = 1;

    input();
    setRoot();
    linkNode();
    answer = solution();
    // for (int i = 0; i <= N; i++)
    //     printf("%d ", root[i]);
    // printf("\n");
    if (answer == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
