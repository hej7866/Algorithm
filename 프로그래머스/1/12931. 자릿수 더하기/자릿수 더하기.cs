using System;

public class Solution 
{
    public int solution(int n) 
    {
        string s = n.ToString();
        int ans = 0;
        foreach(char c in s)
        {
            ans += c - '0';
        }
        return ans;
    }
}