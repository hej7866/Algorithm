using System;

public class Solution 
{
    public long solution(long n) 
    {
        long root = (long)Math.Sqrt(n);
        if (root * root == n)
        {
            // n이 완전 제곱수일 경우 다음 완전 제곱수를 반환
            return (root + 1) * (root + 1);
        }
        // n이 완전 제곱수가 아닐 경우 -1 반환
        return -1;
    }
}