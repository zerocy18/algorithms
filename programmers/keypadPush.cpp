#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<int, int>
using namespace std;

map<int, P> m;

string solution(vector<int> numbers, string hand)
{
    m[1] = P(0, 0);
    m[2] = P(0, 1);
    m[3] = P(0, 2);
    m[4] = P(1, 0);
    m[5] = P(1, 1);
    m[6] = P(1, 2);
    m[7] = P(2, 0);
    m[8] = P(2, 1);
    m[9] = P(2, 2);
    m[0] = P(3, 1);
    string answer = "";
    P rightHand = P(3, 0);
    P leftHand = P(3, 2);
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            leftHand = m[numbers[i]];
            answer.push_back('L');
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            rightHand = m[numbers[i]];
            answer.push_back('R');
        }
        else
        {
            int tempRight = 0;
            int tempLeft = 0;
            tempRight = abs(m[numbers[i]].first - rightHand.first) + abs(m[numbers[i]].second - rightHand.second);
            tempLeft = abs(m[numbers[i]].first - leftHand.first) + abs(m[numbers[i]].second - leftHand.second);
            if (tempRight > tempLeft)
            {
                leftHand = m[numbers[i]];
                answer.push_back('L');
            }
            else if (tempRight < tempLeft)
            {
                rightHand = m[numbers[i]];
                answer.push_back('R');
            }
            else
            {
                if (hand == "right")
                {
                    rightHand = m[numbers[i]];
                    answer.push_back('R');
                }
                else
                {
                    leftHand = m[numbers[i]];
                    answer.push_back('L');
                }
            }
        }
    }
    return answer;
}
