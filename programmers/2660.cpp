#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[51];
vector<int> v[51];
vector<int> selected(51);
int N;

void input()
{
    int a, b;

    scanf("%d", &N);
    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1)
        {
            break;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void setVisit()
{
    for (int i = 0; i <= N; i++)
        visit[i] = false;
}

int bfs(int num)
{
    queue<int> q;
    q.push(num);
    int score = 0;
    visit[num] = true;
    while (!q.empty())
    {
        int qsize = q.size();

        for (int i = 0; i < qsize; i++)
        {
            int cur = q.front();
            //printf("cur : %d, score %d\n", cur, score);
            q.pop();
            for (int j = 0; j < v[cur].size(); j++)
            {
                int next = v[cur][j];
                if (!visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
        score++;
    }
    return score;
}
int main()
{
    vector<int> answer;
    input();
    int min = 1000;
    for (int i = 1; i <= N; i++)
    {
        setVisit();
        selected[i] = bfs(i) - 1;
        //printf("i : %d / %d \n", i, selected[i]);
        if (min > selected[i])
        {
            min = selected[i];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (min == selected[i])
            answer.push_back(i);
    }
    printf("%d %d\n", min, answer.size());
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}
