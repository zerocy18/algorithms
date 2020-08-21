#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;
set<int> s;
const int n = 6;
int board[5][5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt, int num)
{
    if (cnt == n - 1)
    {
        s.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
        {
            dfs(nx, ny, cnt + 1, num * 10 + board[nx][ny]);
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, 0, board[i][j]);
        }
    }
    printf("%d", s.size());
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << "value : " << *it << '\n';
    // }
    return 0;
}
