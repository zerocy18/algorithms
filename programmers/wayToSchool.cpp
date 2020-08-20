#include <string>
#include <vector>
#define INF 1000000007

using namespace std;
int dp[101][101];
int pad[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;


    dp[1][1]=1;
   
    for(int i = 0 ; i < puddles.size(); i++){
        pad[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(i == 1 && j == 1) continue;
            
            if(pad[i][j] == -1){
                dp[i][j] = 0;
            }
            else{
                  dp[i][j] = (dp[i-1][j]%INF + dp[i][j-1]%INF)%INF;
            }
          
        }
    }


    answer = dp[n][m]%INF;
    return answer;
}
