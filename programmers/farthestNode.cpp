#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2123456789

using namespace std;

vector<int> link[20001];
queue<int> q;
int distan[20001];


void bfs(int start){
    int dist = 1;
    distan[start] = dist;
    q.push(start);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0 ; i < sz; i++){
            int cur= q.front();
            q.pop();
            for(int j = 0 ; j < link[cur].size(); j++){
                if(distan[link[cur][j]]==0){
                    distan[link[cur][j]] = dist+1;
                    q.push(link[cur][j]);
                }
            }
        }
        dist++;
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0 ; i < edge.size(); i++){
        link[edge[i][0]].push_back(edge[i][1]);
        link[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    // for(int i = 0 ; i < edge.size(); i++){
    //    printf("%d %d\n", edge[i][0], edge[i][1]);
    //}
    int mxv = -INF;
    for(int i = 1 ; i <= n ; i++){
       if(mxv < distan[i]) mxv = distan[i];
    }
    for(int i = 1; i <= n ; i++){
        if(distan[i] == mxv) answer++;
    }
    return answer;
}
