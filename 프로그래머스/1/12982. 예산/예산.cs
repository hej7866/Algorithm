using System;

public class Solution 
{
    public int solution(int[] d, int budget) 
    {
        Array.Sort(d);
    
        int idx = 0;
        while(budget > 0)
        {
            budget -= d[idx];
            idx++;
            if(idx == d.Length)
            {
                break;
            }
        }

        if(budget < 0)
        {
            idx--;
        }

        return idx;
    }
}