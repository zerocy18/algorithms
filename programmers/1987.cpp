#include <stdio.h>
#include <map>

using namespace std;

int R, C;
char board[20][21];
bool visit[20][20];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
map<char, int> check;
int mxv = -1;

void input()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        scanf("%s", board[i]);
    }
}

void dfs(int x, int y, char now, int cnt)
{
    //printf("%d %d %c %d\n", x, y, now, cnt);

    if (mxv < cnt)
    {
        mxv = cnt;
    }
    check[now] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C)
        {
            if (check[board[nx][ny]] != 1)
            {
                //check[now] = 1;
                dfs(nx, ny, board[nx][ny], cnt + 1);
                check[board[nx][ny]] = 0;
            }
        }
    }
}

int main()
{
    input();
    visit[0][0] = true;
    dfs(0, 0, board[0][0], 1);
    printf("%d", mxv);
    return 0;
}
