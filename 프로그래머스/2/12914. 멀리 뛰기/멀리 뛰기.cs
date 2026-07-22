public class Solution
{
    public long solution(int n)
    {
        const int MOD = 1234567;

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        long prev2 = 1; // dp[1]
        long prev1 = 2; // dp[2]

        for (int i = 3; i <= n; i++)
        {
            long current = (prev1 + prev2) % MOD;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
}