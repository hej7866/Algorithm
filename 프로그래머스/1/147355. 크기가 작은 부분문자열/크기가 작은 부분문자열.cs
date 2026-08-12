using System;

public class Solution 
{
    public int solution(string t, string p) 
    {
        int result = 0;
        for(int i=0; i<=t.Length - p.Length; i++)
        {
            string tmp = "";
            for(int j=i; j<i+p.Length; j++)
            {
                tmp += t[j];
            }
            if(long.Parse(tmp) <= long.Parse(p))
            {
                result++;
            }
        }
        return result;
    }
}