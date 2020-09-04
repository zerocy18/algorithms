#include <stdio.h>
#include <queue>
#define P pair<int, int>

using namespace std;

char board[12][7];
bool visit[12][6];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void input()
{
    for (int i = 0; i < 12; i++)
    {
        scanf("%s", board[i]);
    }
}

void setVisit()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            visit[i][j] = false;
        }
    }
}

bool checkPuyo(int x, int y, char color)
{
    int cnt = 0;
    queue<P> q;
    if (color == '.')
        return false;
    q.push(P(x, y));
    while (!q.empty())
    {
        P now = q.front();
        q.pop();
        cnt++;
        visit[now.first][now.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (0 <= nx && nx < 12 && 0 <= ny && ny < 6)
            {
                if (!visit[nx][ny] && board[nx][ny] == color)
                {
                    q.push(P(nx, ny));
                }
            }
        }
    }

    //setVisit();

    if (cnt > 3)
        return true;
    else
        return false;
}

void popPuyo(int x, int y, char color)
{
    queue<P> q;
    q.push(P(x, y));
    while (!q.empty())
    {
        P now = q.front();
        board[now.first][now.second] = '.';
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (0 <= nx && nx < 12 && 0 <= ny && ny < 6)
            {
                if (board[nx][ny] == color)
                {
                    q.push(P(nx, ny));
                }
            }
        }
    }
}

void dropPuyo()
{
    for (int i = 10; i >= 0; i--)
    {
        for (int j = 5; j >= 0; j--)
        {
            if (board[i][j] != '.' && board[i + 1][j] == '.')
            {
                int k;
                for (k = 1;; k++)
                {
                    if (board[i + k][j] == '.')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                k--;
                board[i + k][j] = board[i][j];
                board[i][j] = '.';
            }
        }
    }
}

int main()
{
    input();
    queue<P> pos;
    int answer = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (checkPuyo(i, j, board[i][j]))
            {
                pos.push(P(i, j));
            }
        }
    }
    if (!pos.empty())
    {
        while (1)
        {
            while (!pos.empty())
            {
                P cur = pos.front();
                popPuyo(cur.first, cur.second, board[cur.first][cur.second]);
                pos.pop();
            }
            // printf("______\n");
            // for (int i = 0; i < 12; i++)
            // {
            //     for (int j = 0; j < 6; j++)
            //     {
            //         printf("%c", board[i][j]);
            //     }
            //     printf("\n");
            // }
            answer++;
            dropPuyo();

            setVisit();
            // printf("______\n");
            // for (int i = 0; i < 12; i++)
            // {
            //     for (int j = 0; j < 6; j++)
            //     {
            //         printf("%c", board[i][j]);
            //     }
            //     printf("\n");
            // }
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (checkPuyo(i, j, board[i][j]))
                    {
                        pos.push(P(i, j));
                    }
                }
            }
            if (pos.empty())
            {
                break;
            }
        }
    }

    printf("%d", answer);
    // for (int i = 0; i < 12; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         printf("%c", board[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
