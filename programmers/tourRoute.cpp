#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool checked[10000];
string answerString = "a";
void dfs(vector<vector<string>> tickets, string st, int size, string path)
{
    if (size == tickets.size())
    {
        if (answerString > path)
        {
            answerString = path;
        }
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (st == tickets[i][0] && !checked[i])
        {
            checked[i] = true;
            dfs(tickets, tickets[i][1], size + 1, path + tickets[i][1]);
            checked[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());

    dfs(tickets, "ICN", 0, "ICN");
    for (int i = 0; i < answerString.length(); i += 3)
    {
        answer.push_back(answerString.substr(i, 3));
    }
    return answer;
}
