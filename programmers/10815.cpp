#include <stdio.h>
#include <map>

using namespace std;
map<int, int> mm;
int n, m;
int have[500000];
int main()
{
    int a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        mm[a]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        if (mm[a] == 1)
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }

    return 0;
}
