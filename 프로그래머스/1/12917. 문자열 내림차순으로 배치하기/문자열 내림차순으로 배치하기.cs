using System;

public class Solution 
{
    public string solution(string s) 
    {
        char[] charArr = s.ToCharArray();
        Array.Sort(charArr);
        Array.Reverse(charArr);
        
        string ans = new string(charArr);
        return ans;
    }
}