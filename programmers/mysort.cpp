#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string,char> a, pair<string,char> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<string, char>> v;
    for(int i =0 ; i < strings.size(); i++){
        v.push_back(make_pair(strings[i],strings[i][n]));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0 ; i < strings.size(); i++){
        answer.push_back(v[i].first);
    }
    return answer;
}