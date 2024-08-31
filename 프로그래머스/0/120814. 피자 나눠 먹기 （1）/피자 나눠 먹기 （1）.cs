using System;

public class Solution 
{
    public int solution(int n) 
    {
        int count = 1;
        while(count * 7 < n)
        {
            count++;
        }
        return count;
    }
}