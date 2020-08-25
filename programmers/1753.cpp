#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define P pair<int, int>
#define G greater<P>
#define INF 2123456789

using namespace std;

int V, E, K;
vector<P> connection[20001];  // first: node , second: weight
vector<int> dist(20001, INF); // first: weight,  second : node
priority_queue<P, vector<P>, G> pq;

void input()
{
    int u, v, w;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        connection[u].push_back(P(v, w));
    }
}

int main()
{
    input();
    dist[K] = 0;
    pq.push(P(0, K));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (dist[curr] < cost)
        {
            continue;
        }
        int size = connection[curr].size();
        for (int i = 0; i < size; i++)
        {
            int neighbor = connection[curr][i].first;
            int nextCost = cost + connection[curr][i].second;
            if (dist[neighbor] > nextCost)
            {
                dist[neighbor] = nextCost;
                pq.push(P(nextCost, neighbor));
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }
    return 0;
}
