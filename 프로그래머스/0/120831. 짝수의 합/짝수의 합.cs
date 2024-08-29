using System;

public class Solution 
{
    public int solution(int n) 
    {
        int evenSum = 0;
        for(int i=1; i<=n; i++)
        {
            if(i%2 == 0)
            {
                evenSum += i;
            }
        }
        return evenSum;
    }
}