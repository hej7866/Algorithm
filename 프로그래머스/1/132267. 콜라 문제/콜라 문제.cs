using System;

public class Solution 
{
    public int solution(int a, int b, int n) 
    {
        int count = 0;
        while(n / a > 0)
        {
            int t1 = n / a;
            int t2 = t1 * a;
            count += t1 * b;
            n -= t2;
            n += t1 * b;
        }
        return count;
    }
}