#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long maxi, mini;
    maxi = max(a,b);
    mini = min(a,b);
    if(a==b){
        answer = a;
    }
    else{
        for(long long i = mini ; i <= maxi ; i++ ){
            answer += i;
        }
    }
    return answer;
}