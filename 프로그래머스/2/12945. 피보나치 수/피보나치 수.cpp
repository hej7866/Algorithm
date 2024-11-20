#include <string>
#include <vector>

using namespace std;

int FibDp(int n) // DP
{
	int* dp = new int[n + 1];

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
	}
	return dp[n];
}

int solution(int n) 
{
    int answer = FibDp(n);
    return answer;
}