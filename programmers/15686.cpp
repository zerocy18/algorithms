#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define INF 2123456789
using namespace std;
int answer = INF;
int N, M;
int city[50][50];
vector<P> store;
vector<P> selectStore;
vector<P> house;
void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &city[i][j]);
            if (city[i][j] == 1)
                house.push_back(P(i, j));
            else if (city[i][j] == 2)
                store.push_back(P(i, j));
        }
    }
}

int calcDist()
{
    int ret = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int temp = INF;
        for (int j = 0; j < selectStore.size(); j++)
        {
            temp = min(temp, abs(house[i].first - selectStore[j].first) + abs(house[i].second - selectStore[j].second));
        }
        ret += temp;
    }
    return ret;
}

void dfsCombination(int num, int cnt)
{
    if (cnt == M)
    {
        int sol = calcDist();
        if (answer > sol)
        {
            answer = sol;
        }
        return;
    }
    else
    {
        for (int i = num; i < store.size(); i++)
        {
            selectStore.push_back(store[i]);
            dfsCombination(i + 1, cnt + 1);
            selectStore.pop_back();
        }
    }
}

int main()
{
    input();
    dfsCombination(0, 0);
    printf("%d", answer);
    return 0;
}