#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int index = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {  
        index = i -cnt;
        if(s[i] == ' '){
            cnt=i+1;
            continue;
        }
        if(index%2 == 0){
            s[i] = toupper(s[i]);
        }
        else{
            s[i] = tolower(s[i]);
        }
    }
    answer = s;
    return answer;
}