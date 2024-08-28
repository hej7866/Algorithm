using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n) 
    {
        List<int> composite = new List<int>();
        for(int i=1; i<=n; i++)
        {
            int count = 0;
            for(int j=1; j<=i; j++)
            {
                if(i%j == 0)
                {
                    count++;
                }
            }
            if(count >= 3)
            {
                composite.Add(i);
            }
        }
        return composite.Count;
    }
}