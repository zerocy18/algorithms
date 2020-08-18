#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h,w;
    int sum = (brown-4) /2;
    for(h = 1; h<=yellow ; h++){
        for(w = h ; w<=yellow; w++){
            if(w*h == yellow && w+h == sum){
                answer.push_back(w+2);
                answer.push_back(h+2);
                break;
            }
        }
        if(!answer.empty()) break;
    }
    return answer;
}
