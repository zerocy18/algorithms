//using DP
#include <string>
#include <vector>
#define N 1234567

using namespace std;

long long dp[2001];

long long solution(int n)
{
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] % N + dp[i - 1] % N) % N;
    }
    answer = dp[n];
    return answer;
}
