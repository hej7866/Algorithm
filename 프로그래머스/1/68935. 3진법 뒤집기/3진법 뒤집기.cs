using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n) 
    {
        List<int> ans = new List<int>();
        while(n / 3 != 0)
        {
            ans.Add(n % 3);
            n /= 3;
        }
        ans.Add(n % 3);
      
        ans.Reverse();
        
        int result = 0;
        int pow = 1;
        for(int i=0; i<ans.Count; i++)
        {
            result += pow * ans[i];
            pow *= 3;
        }
        
        return result;
    }
}