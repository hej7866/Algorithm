using System;

public class Solution 
{
    public int solution(int n) 
    {
        int i = 1;
        int count = 1;
        while(i <= n)
        {
            i *= (count + 1);
            count++;
        }
        return count - 1;
    }
}