#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n)
{
    string answer = "";
    string ans = "";
    while (n > 0)
    {
        if (n % 3 == 0)
        {
            ans += '4';
            n = n / 3 - 1;
        }
        else if (n % 3 == 1)
        {
            ans += '1';
            n = n / 3;
        }
        else
        {
            ans += '2';
            n = n / 3;
        }
    }
    for (int i = ans.length() - 1; i >= 0; i--)
    {
        answer += ans[i];
    }
    return answer;
}
int main()
{
    cout << solution(4) << '\n';
    return 0;
}
