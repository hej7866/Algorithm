using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public long solution(long n) 
    {
        string strN = n.ToString();
        
        List<int> list = new List<int>();
        foreach(char c in strN)
        {
            list.Add(c - '0');
        }
        var sortedNumbers = list.OrderByDescending(num => num).ToList();
        
        string ans = "";
        foreach(int i in sortedNumbers)
        {
            ans += i.ToString();
        }
        return long.Parse(ans);
    }
}