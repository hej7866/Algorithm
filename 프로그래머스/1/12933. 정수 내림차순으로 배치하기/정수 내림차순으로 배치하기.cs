using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public long solution(long n) 
    {
        string s = n.ToString();
        List<char> c = new List<char>(s.ToList());
        
        List<char> ans = c.OrderByDescending(x => x).ToList();
        
        string a = new string(ans.ToArray());
        long result = long.Parse(a);
        return result;
    }
}