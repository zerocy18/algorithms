#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int sum[] = {0 ,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int total = sum[a-1]+b;
    if(total%7 == 1) answer = "FRI";
    else if(total%7 == 2) answer = "SAT";
    else if(total%7 == 3) answer ="SUN";
    else if(total%7 == 4) answer = "MON";
    else if(total%7 == 5) answer = "TUE";
    else if(total%7 == 6) answer = "WED";
    else answer = "THU";
    return answer;
}