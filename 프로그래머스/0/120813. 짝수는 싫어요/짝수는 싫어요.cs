using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int n) 
    {
        List<int> oddList = new List<int>();
        
        for(int i=1; i<=n; i++)
        {
            if(i%2 == 1)
            {
                oddList.Add(i);  
            }
        }
        return oddList.ToArray();
    }
}