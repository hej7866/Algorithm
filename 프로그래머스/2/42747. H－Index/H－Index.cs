using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int[] citations) 
    {
        List<int> sorted = new List<int>(citations);
        sorted = sorted.OrderByDescending(x => x).ToList();
        
        int max = 0;
        for(int i=0; i<sorted.Count; i++)
        {
            if(sorted[i] >= i+1)
            {
                max = i + 1;
            }
        }
        return max;
    }
}