#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int wrong=0;
    vector<int> answer;
    map<string, int> m;
    m[words[0]]++;
    for(int i = 1 ; i < words.size() ; i++){
        if(m[words[i]]==0){
            m[words[i]]++;
        }
        else{
            wrong = i+1;
            break;
        }
        
        if(words[i-1].back() != words[i][0]){
            wrong = i+1;
            break;
        }
    }
    
    if(wrong == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        //printf("%d", wrong);
        int num;
        int order;
        if(wrong % n == 0){
            num = n;
            order = wrong/n;
        }
        else{
            num = wrong%n;
            order = wrong/n +1;
        }
        answer.push_back(num);
        answer.push_back(order);
    }
    


    return answer;
}
