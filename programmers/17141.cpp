#include <stdio.h>
#include <queue>
#include <vector>
#define P pair<int, int>
#define INF 2123456789

using namespace std;
vector<P> virus;
vector<P> selectVirus;
int answer = INF;
int N, M;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int board[50][50];

void input()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);

            if (board[i][j] == 2)
            {
                virus.push_back(P(i, j));
            }
        }
    }
}
int spread()
{
    int nowBoard[50][50];
    int time = 0;
    queue<P> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            nowBoard[i][j] = 0;
            if (board[i][j] == 1)
                nowBoard[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < selectVirus.size(); i++)
    {
        nowBoard[selectVirus[i].first][selectVirus[i].second] = 2;
        q.push(selectVirus[i]);
    }
    // printf("+++++++++++++++++\n");
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         printf("%d ", nowBoard[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("+++++++++++++++++\n");
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N)
                {
                    if (nowBoard[nx][ny] == 0)
                    {
                        nowBoard[nx][ny] = 2;
                        q.push(P(nx, ny));
                    }
                }
            }
        }
        time++;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (nowBoard[i][j] == 0)
                return INF;
    return time - 1;
}

void dfsCombination(int num, int cnt)
{
    if (cnt == M)
    {
        int temp = spread();
        if (answer > temp)
        {
            answer = temp;
        }
    }
    else
    {
        for (int i = num; i < virus.size(); i++)
        {
            selectVirus.push_back(virus[i]);
            dfsCombination(i + 1, cnt + 1);
            selectVirus.pop_back();
        }
    }
}
int main()
{
    input();
    dfsCombination(0, 0);
    if (answer == INF)
    {
        printf("-1");
    }
    else
        printf("%d", answer);
    return 0;
}
