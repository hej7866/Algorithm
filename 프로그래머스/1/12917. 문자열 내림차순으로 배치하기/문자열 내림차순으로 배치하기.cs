using System;
using System.Linq;

public class Solution 
{
    public string solution(string s) 
    {
        char[] ans = s.OrderByDescending(x => x).ToArray();
        
        return new string(ans);
    }
}