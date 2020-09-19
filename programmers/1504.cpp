#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define G greater<P> // first : cost, second : node
#define INF 800100
using namespace std;

vector<P> link[801];

int N, E;
int v1, v2;
void input()
{
    int sNode, eNode, cost;
    scanf("%d %d", &N, &E);
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &sNode, &eNode, &cost);
        link[sNode].push_back(P(cost, eNode));
        link[eNode].push_back(P(cost, sNode));
    }
    scanf("%d %d", &v1, &v2);
}

int dijkstra(int startPoint, int endPoint)
{
    priority_queue<P, vector<P>, G> pq;
    vector<int> dist(801, INF);
    pq.push(P(0, startPoint));
    dist[startPoint] = 0;
    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (dist[curNode] < curCost)
        {
            continue;
        }

        for (int i = 0; i < link[curNode].size(); i++)
        {
            int neigbor = link[curNode][i].second;
            int nextCost = curCost + link[curNode][i].first;
            if (dist[neigbor] > nextCost)
            {
                dist[neigbor] = nextCost;
                pq.push(P(nextCost, neigbor));
            }
        }
    }
    return dist[endPoint];
}
int main()
{
    input();
    int sum1 = 0, sum2 = 0;

    sum1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);

    sum2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

    int answer = min(sum1, sum2);
    if (answer >= INF)
        printf("-1");
    else
    {
        printf("%d", answer);
    }

    return 0;
}
