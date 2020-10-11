#include <stdio.h>

int dice[7];
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
int N, M, x, y, K;
int board[20][20];
int main()
{
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 0; i < K; i++)
    {
        int dir;
        scanf("%d", &dir);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int nDice[7];
        for (int i = 1; i < 7; i++)
        {
            nDice[i] = dice[i];
        }
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
            continue;
        }

        switch (dir)
        {
        case 1:
            dice[6] = nDice[3];
            dice[3] = nDice[1];
            dice[1] = nDice[4];
            dice[4] = nDice[6];
            break;
        case 2:
            dice[1] = nDice[3];
            dice[4] = nDice[1];
            dice[6] = nDice[4];
            dice[3] = nDice[6];
            break;
        case 3:
            dice[1] = nDice[5];
            dice[2] = nDice[1];
            dice[6] = nDice[2];
            dice[5] = nDice[6];
            break;
        case 4:
            dice[1] = nDice[2];
            dice[5] = nDice[1];
            dice[6] = nDice[5];
            dice[2] = nDice[6];
            break;
        }

        if (board[nx][ny] == 0)
        {
            board[nx][ny] = dice[6];
        }
        else
        {
            dice[6] = board[nx][ny];
            board[nx][ny] = 0;
        }
        printf("%d\n", dice[1]);
        x = nx;
        y = ny;
    }
    return 0;
}
