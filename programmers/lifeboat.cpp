#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i = 0;
    int j = people.size()-1;
    sort(people.begin(), people.end(),cmp);
    int sum=0;
    int cnt=0;
    while(true){
        sum+=people[i];
        i++;
        while(sum+people[i]<=limit){
            sum+= people[i];
            i++;
        }
        while(sum+people[j] <= limit){
            sum+= people[j];
            j--;
        }
        cnt++;

        if(i > j)
            break;
        sum=0;
    }
    for(int i = 0  ;i < people.size(); i++)
        printf("%d", people[i]);
    answer = cnt;
    return answer;
}
