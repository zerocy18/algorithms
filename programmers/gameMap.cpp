#include <vector>
#include <queue>
#define P pair<int, int>
using namespace std;
queue<P> q;
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int h,w;
int bfs(int x, int y)
{
    int cnt = 1;
    visited[x][y] = true;
    q.push(P(x, y));
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if(curX == h-1 && curY == w-1) return cnt;
            for (int i = 0; i < 4; i++)
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                
                if (0 <= newX && newX < h && 0 <= newY && newY < w)
                {
                    if (!visited[newX][newY] && board[newX][newY] == 1)
                    {
                        visited[newX][newY] = true;
                        q.push(P(newX, newY));
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            board[i][j] = maps[i][j];
        }
    }
    h = maps.size();
    w = maps[0].size();
    answer = bfs(0, 0);
    return answer;
}
