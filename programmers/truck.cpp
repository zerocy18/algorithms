#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur = 0; 
    queue<int> q;
    int idx = 0; 
    
    while(1){
        answer++;
        if(q.size() == bridge_length){
            cur-= q.front();
            q.pop();
        }
        
        if(cur+truck_weights[idx] <= weight){
            if(idx == truck_weights.size()-1){
                answer+= bridge_length;
                break;
            }
            q.push(truck_weights[idx]);
            cur+= truck_weights[idx];
            idx++;
        }
        else{
            q.push(0);
        }
    }
    
    return answer;
}
