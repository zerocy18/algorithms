#include <stdio.h>
#include <vector>
#include <queue>
#define INF 2123456789
#define P pair<int, int>
#define G greater<P>

using namespace std;

int N, M;
int startCity, endCity;
vector<P> connection[1001]; //first:node, second : weight
vector<int> dist(1001, INF);
priority_queue<P, vector<P>, G> pq; //first:weight, second: node

void input()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        connection[a].push_back(P(b, c));
    }
    scanf("%d", &startCity);
    scanf("%d", &endCity);
}

int main()
{
    input();
    dist[startCity] = 0;
    pq.push(P(0, startCity));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost)
        {
            continue;
        }
        int size = connection[cur].size();
        for (int i = 0; i < size; i++)
        {
            int neighbor = connection[cur][i].first;
            int nextCost = cost + connection[cur][i].second;
            if (dist[neighbor] > nextCost)
            {
                dist[neighbor] = nextCost;
                pq.push(P(nextCost, neighbor));
            }
        }
    }
    printf("%d", dist[endCity]);
    return 0;
}
