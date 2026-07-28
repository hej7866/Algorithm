using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] arr, int divisor) 
    {
        List<int> results = new List<int>();
        foreach(var n in arr)
        {
            if(n%divisor == 0)
            {
                results.Add(n);
            }
        }
        int[] ans = results.ToArray();
        Array.Sort(ans);
        return ans.Length == 0 ? new int[] {-1} : ans;
    }
}