#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 2123456789
using namespace std;

int mincnt = INF;
bool visited[50];

void dfs(string startword, string endword, vector<string> words, int n)
{
    //cout << n << ": " << startword << "\n";
    if (startword == endword)
    {
        if (mincnt > n)
            mincnt = n;
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        int df = 0;
        for (int j = 0; j < startword.length(); j++)
        {
            if (startword[j] != words[i][j])
            {
                df++;
            }
        }
        if (df == 1 && !visited[i])
        {
            visited[i] = true;
            dfs(words[i], endword, words, n + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    dfs(begin, target, words, 0);
    answer = mincnt;
    if (answer == INF)
    {
        answer = 0;
    }
    return answer;
}

int main()
{
    vector<string> v;
    v.push_back("hot");
    v.push_back("dot");
    v.push_back("dog");
    v.push_back("lot");
    v.push_back("log");
    v.push_back("cog");
    int an = solution("hit", "cog", v);
    printf("%d", an);
    return 0;
}
