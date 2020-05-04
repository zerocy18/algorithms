#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int cnt = 0;

    for(int i = 0 ; i <progresses.size(); i++){
        int date;
        int cnt = 0;
        date = (100-progresses[i])/speeds[i];
        if(((100-progresses[i])%speeds[i])!=0){
            date+=1;
        }
        q.push(date);
    }
    int howlong = q.front();
    while(!q.empty()){
        if(howlong >= q.front()){
            q.pop();
            cnt++;
        }
        else{
            answer.push_back(cnt);
            cnt = 0;
            howlong = q.front();
        }
    }
    if(cnt!=0){
        answer.push_back(cnt);
    }
    
    return answer;
}