using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n) 
    {
        List<int> list = new List<int>();
        while(n > 0)
        {
            list.Add(n%3);
            n /= 3;
        }
        
        int ans = 0;
        int t = 1;
        for(int i = list.Count - 1; i >= 0; i--)
        {
            ans += list[i] * t;
            t *= 3;  
        }
        return ans;
    }
}