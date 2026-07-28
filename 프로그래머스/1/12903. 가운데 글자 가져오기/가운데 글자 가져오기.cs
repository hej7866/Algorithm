using System;

public class Solution 
{
    public string solution(string s) 
    {
        int i = s.Length - 1;
        
        string result = "";
        if(i%2 == 0)
        {
            result = s[i/2].ToString();
        }
        else
        {
            result = s[i/2].ToString();
            result += s[i/2 + 1].ToString();
        }
        return result;
    }
}