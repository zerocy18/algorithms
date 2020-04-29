#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    if(len%2 == 0){
        answer.push_back(s[len/2 -1]);
        answer.push_back(s[len/2]);
    }
    else{
        answer = s[len /2];
    }

    return answer;
}