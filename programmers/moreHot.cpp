//priority_queue 사용법 숙지
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>,greater<int> > pq;
    
    for(int i = 0 ; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }    
    
    int answer = 0;
    int first, second;
    int newFood;
    while(1){
        first = pq.top();
        pq.pop();
        if(pq.empty()) break;
        second = pq.top();
        pq.pop();
        
        newFood = first+ 2*second;
        pq.push(newFood);
        answer++;
        if(pq.top() > K){
            break;
        }
        if(pq.empty()) break;
    }
    if(pq.empty()) return -1;
    return answer;
}
