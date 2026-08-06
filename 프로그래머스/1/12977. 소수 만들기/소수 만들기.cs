using System;

public class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        int n = nums.Length;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (IsPrime(sum))
                    {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }

    private bool IsPrime(int num)
    {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }
}