#include <stdio.h>
#include <queue>
#define P pair<int, int>

using namespace std;
// 뱀 1, 벽 2 , 사과 3

int board[102][102];
char turned[10001];
int n, k, l;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer;
queue<P> snake;

void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
            {
                board[i][j] = 2;
            }
        }
    }
    board[1][1] = 1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        board[a][b] = 3;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        turned[a] = b;
    }
}

bool canGo(int x, int y)
{
    if (board[x][y] == 2 || board[x][y] == 1)
        return false;
    else
        return true;
}

int doTurn(char c, int dir)
{
    int location;
    if (c == 'D')
    {
        location = dir + 1;
        location %= 4;
    }
    else if (c == 'L')
    {
        location = (dir - 1) + 4;
        location %= 4;
    }
    return location;
}

void going(int x, int y)
{
    snake.push(P(x, y));
    int nx = x, ny = y;
    int location = 0;
    while (1)
    {
        P tail = snake.front();
        nx = nx + dx[location];
        ny = ny + dy[location];
        answer++;
        if (!canGo(nx, ny))
            break;
        if (turned[answer])
        {
            location = doTurn(turned[answer], location);
        }
        if (board[nx][ny] == 3)
        {
            snake.push(P(nx, ny));
            board[nx][ny] = 1;
        }
        if (board[nx][ny] == 0)
        {
            snake.push(P(nx, ny));
            snake.pop();
            board[nx][ny] = 1;
            board[tail.first][tail.second] = 0;
        }
        // printf("answer = %d\n", answer);
        // for (int i = 0; i < 20; i++)
        // {
        //     for (int j = 0; j < 20; j++)
        //     {
        //         printf("%d", board[i][j]);
        //     }
        //     printf("\n");
        // }
    }
}

int main()
{
    input();
    going(1, 1);

    printf("%d", answer);

    return 0;
}
