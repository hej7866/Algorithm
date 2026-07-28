using System;

public class Solution
{
    public long solution(int a, int b)
    {
        int min = Math.Min(a, b); // 작은값
        int max = Math.Max(a, b); // 큰값

        return ((long)min + max) * (max - min + 1) / 2;
    }
}