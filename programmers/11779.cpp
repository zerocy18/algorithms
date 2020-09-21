#include <stdio.h>
#include <queue>
#include <vector>
#define INF 2123456789
#define P pair<int, int> // first : cost, end : destination
#define G greater<P>
using namespace std;

int n, m;
vector<P> link[1001];
vector<int> dist(1001, INF);
vector<int> previ(1001, -1);
vector<int> path;

int startCity, endCity;

void input()
{
    int startNode, endNode, cost;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &startNode, &endNode, &cost);
        link[startNode].push_back(P(cost, endNode));
    }
    scanf("%d %d", &startCity, &endCity);
}

void dijstra()
{
    priority_queue<P, vector<P>, G> pq;
    pq.push(P(0, startCity));
    dist[startCity] = 0;
    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curCity = pq.top().second;
        pq.pop();
        if (dist[curCity] < curCost)
        {
            continue;
        }

        for (int i = 0; i < link[curCity].size(); i++)
        {
            int nextCost = curCost + link[curCity][i].first;
            int nextCity = link[curCity][i].second;
            if (nextCost < dist[nextCity])
            {
                dist[nextCity] = nextCost;
                pq.push(P(nextCost, nextCity));
                previ[nextCity] = curCity;
            }
        }
    }
}

void tracking()
{
    int now = endCity;
    while (now != -1)
    {
        path.push_back(now);
        now = previ[now];
    }
    printf("%d\n", path.size());
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
}

int main()
{
    input();
    dijstra();
    printf("%d\n", dist[endCity]);
    tracking();
    return 0;
}
