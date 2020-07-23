#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a> b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), desc);
    sort(B.begin(), B.end(), desc);
    int i,j=0;
    for(i= 0 ; i < B.size(); i++){
        for( ; j < A.size(); j++){
            if(B[i]>A[j]){
                answer++;
                j++;
                break;
            }
        }
    }
    return answer;
}
