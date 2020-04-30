#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    for(int i = 0; i < s.length() ; i++){
        if(s[i]<'0' || s[i]>'9'){
            answer = false;
            break;
        }
    }
    if(s.length() != 4 && s.length() != 6){
        answer = false;
    }
    return answer;
}