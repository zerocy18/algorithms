#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> student(n, 1);
    for (int i = 0; i < lost.size(); i++)
    {
        int losted = lost[i] - 1;
        student[losted]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        int reserved = reserve[i] - 1;
        student[reserved]++;
    }
    for (int i = 0; i < n; i++)
    {   /*
        왼쪽부터 채워줘야함!!!
        */
        if (student[i] == 2 && i > 0 && student[i - 1] == 0) 
        {
            student[i]--;
            student[i - 1]++;
        }
        if (student[i] == 2 && i < n - 1 && student[i + 1] == 0)
        {
            student[i]--;
            student[i + 1]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (student[i] > 0)
            answer++;
    }
    return answer;
}