using System;

public class Solution 
{
    public int solution(int slice, int n) 
    {
        int count = 1;
        while(slice * count < n)
        {
            if(slice < n)
            {
                count++;
            }
        }
        return count;
    }
}