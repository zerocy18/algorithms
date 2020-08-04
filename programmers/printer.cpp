#include <string>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

queue<P> print;
priority_queue<int> ranky;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    P cur;
    for (int i = 0; i < priorities.size(); i++)
    {
        print.push(P(i, priorities[i]));
        ranky.push(priorities[i]);
    }
    while(1)
    {
        cur = print.front();
        print.pop();
        if (cur.second == ranky.top())
        {
            ranky.pop();
            answer++;
            if(cur.first == location){
                
                break;
            }
        }
        else{
            print.push(cur);
        }
    }
    return answer;
}
