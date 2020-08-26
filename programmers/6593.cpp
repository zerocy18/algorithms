#include <stdio.h>
#include <queue>

using namespace std;

char building[50][50][51];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
bool visited[50][50][50];
int l, r, c;

typedef struct xyz
{
    int z;
    int x;
    int y;
} xyz;

xyz st, en;
void setVisited()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            for (int k = 0; k < 50; k++)
            {
                visited[i][j][k] = false;
            }
        }
    }
}
int bfs(int z, int x, int y)
{
    queue<xyz> q;
    visited[z][x][y] = true;
    q.push((xyz){z, x, y});
    int min = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int curx = q.front().x;
            int cury = q.front().y;
            int curz = q.front().z;
            //printf("enz: %d, enx: %d, eny : %d\n", en.z, en.x, en.y);
            //printf("z: %d, x: %d, y :%d\n", curz, curx, cury);
            q.pop();

            if (curx == en.x && cury == en.y && curz == en.z)
            {
                //printf("min : %d", min);
                return min;
            }
            for (int j = 0; j < 6; j++)
            {
                int newx = curx + dx[j];
                int newy = cury + dy[j];
                int newz = curz + dz[j];
                if (0 <= newx && newx < r && 0 <= newy && newy < c && 0 <= newz && newz < l)
                {
                    if (!visited[newz][newx][newy] && (building[newz][newx][newy] == '.' || building[newz][newx][newy] == 'E'))
                    {
                        q.push((xyz){newz, newx, newy});
                        visited[newz][newx][newy] = true;
                    }
                }
            }
        }
        min++;
    }
    return -1;
}

int main()
{
    int answer;
    while (1)
    {
        scanf("%d %d %d", &l, &r, &c);
        if (l == 0 && r == 0 && c == 0)
        {
            break;
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                scanf("%s", building[i][j]);
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    if (building[i][j][k] == 'S')
                    {
                        st = (xyz){i, j, k};
                    }
                    if (building[i][j][k] == 'E')
                    {
                        en = (xyz){i, j, k};
                    }
                }
            }
        }
        setVisited();
        answer = bfs(st.z, st.x, st.y);
        if (answer < 0)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n", answer);
        }
    }
    return 0;
}
