#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//min_element 사용 방법 * 안붙이면 인덱스임
// vector.erase() 잘 쓰자
// find 써도댐!!
vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int minmum = *min_element(answer.begin(), answer.end());
    for(int i = 0 ; i < answer.size() ; i++){
        if(minmum == answer[i]){
            answer.erase(answer.begin()+i);
            break;
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}