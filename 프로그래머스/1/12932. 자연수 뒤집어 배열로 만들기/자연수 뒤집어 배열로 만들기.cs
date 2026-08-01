using System;
public class Solution 
{
    public int[] solution(long n) 
    {
        string s = n.ToString();
        int[] ans = new int[s.Length];
        for(int i = 0; i < s.Length; i++)
        {
            ans[i] = s[s.Length - 1 - i] - '0';
        }
        return ans;
    }
}