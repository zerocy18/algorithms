#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#define P pair<int, int>

using namespace std;
char boardd[30][30];

const int dx[] = {1, 0, 1};
const int dy[] = {1, 1, 0};

bool checkSquare(int x, int y)
{
    if (boardd[x][y] == '.')
        return false;
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (boardd[x][y] != boardd[nx][ny])
        {
            return false;
        }
    }
    return true;
}

void dropBlock(int m, int n)
{
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (boardd[i][j] != '.' && boardd[i + 1][j] == '.')
            {
                int k;
                for (k = 1;; k++)
                {
                    if (boardd[i + k][j] == '.')
                        continue;
                    else
                    {
                        break;
                    }
                }
                k--;
                boardd[i + k][j] = boardd[i][j];
                boardd[i][j] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    queue<P> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            boardd[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (checkSquare(i, j))
            {
                q.push(P(i, j));
            }
        }
    }
    while (1)
    {
        while (!q.empty())
        {
            P now = q.front();
            q.pop();
            if (boardd[now.first][now.second] != '.')
            {
                //printf("%d %d\n", now.first, now.second);
                answer++;
            }
            boardd[now.first][now.second] = '.';
            for (int i = 0; i < 3; i++)
            {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if (boardd[nx][ny] != '.')
                {
                    printf("%d %d\n", nx, ny);
                    answer++;
                }
                boardd[nx][ny] = '.';
            }
            // 떨구는 부분
        }
        dropBlock(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c", boardd[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (checkSquare(i, j))
                {
                    q.push(P(i, j));
                }
            }
        }
        if (q.empty())
        {
            break;
        }
    }
    return answer;
}
