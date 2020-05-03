#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size(); i++){
        for(int j = i +1 ; j < phone_book.size() ; j++){
            // 이렇게 안하고 어차피 소트 되어있으므로 바로 다음것과 비교만 해도댐!!
            if(phone_book[j].find(phone_book[i])==0) 
            {
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}