#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first!= b.first) return a.first> b.first;
    else return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v;
    sort(stages.begin(), stages.end());
    int k=0;
    for(int i =1 ; i<=N;i++){
        int cnt=0;
        for(;k<stages.size();k++ ){
            if(i == stages[k]){
                cnt++;
            }
            else{
                break;
            }
        }
        printf("i : %d, fail: %f\n", i, (double)cnt/(stages.size()-k+cnt));
        if((stages.size()-k+cnt) == 0) {
            v.push_back(pair<double,int>(0,i));
        }
        else{
             v.push_back(pair<double,int>((double)cnt/(stages.size()-k+cnt),i));
        }
       
    }
    sort(v.begin(), v.end(),cmp);
    for(int i = 0 ; i < N ; i++)
        answer.push_back(v[i].second);
    return answer;
}
