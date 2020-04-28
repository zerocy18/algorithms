#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i = 0 ; i < answers.size(); i++){
        if(answers[i] == v1[i%5]){
            cnt1++;
        }
        if(answers[i] == v2[i%8]){
            cnt2++;
        }
        if(answers[i] == v3[i%10]){
            cnt3++;
        }
    }
    int maxcnt = max(cnt1,max(cnt2, cnt3));
    if(maxcnt == cnt1) answer.push_back(1);
    if(maxcnt == cnt2) answer.push_back(2);
    if(maxcnt == cnt3) answer.push_back(3);
    return answer;
}