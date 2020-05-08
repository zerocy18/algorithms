#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0 ; i < s.length() ; i++){
        if(i == 0){
            s[i] = toupper(s[i]);
        }
        if(s[i] == ' '){
            s[i+1]= toupper(s[i+1]);
        }
        else{
            s[i+1] = tolower(s[i+1]);
        }
    }
    answer = s;
    return answer;
}