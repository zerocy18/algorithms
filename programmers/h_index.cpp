#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int high=0;
    sort(citations.begin(), citations.end());
    for(int i =0 ; i <= citations.size(); i++)
    {
        for(int j = 0 ; j < citations.size() ; j++){
            if(citations[j]>=i) high++;
        }
        if(high>=i) answer = i;
        high = 0;
    }

    return answer;
}
