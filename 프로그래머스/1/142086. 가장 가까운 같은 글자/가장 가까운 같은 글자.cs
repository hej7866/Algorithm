using System;

public class Solution 
{
    public int[] solution(string s) 
    {
        int[] result = new int[s.Length];
        for(int i=0; i<s.Length; i++)
        {
            char c = s[i];
            bool isMatch = false;
            for(int j=i-1; j>=0; j--)
            {
                if(c == s[j])
                {
                    result[i] = i - j;
                    isMatch = true;
                    break;
                }
            }
            if(!isMatch)
            {
                result[i] = -1;
            }
        }
        return result;
    }
}