#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> s;

    for (int i = 0; i < moves.size(); i++)
    {
        int select = moves[i] - 1;
        for (int j = 0; j < board[select].size(); j++)
        {
            if (board[j][select] != 0)
            {
                if (!s.empty() && s.top() == board[j][select])
                {
                    s.pop();
                    answer += 2;
                }
                else
                {
                    s.push(board[j][select]);
                }
                board[j][select]= 0;

                break;
            }
        }
    }

    return answer;
}