using System;

public class Solution 
{
    public bool solution(int x) 
    {
        string s = x.ToString();
        char[] c = s.ToCharArray();
        int[] ans = new int[c.Length];
        
        for(int i=0; i<c.Length; i++)
        {
            ans[i] = c[i]-'0';
        }
        
        int a = 0;
        foreach(int i in ans)
        {
            a += i;
        }
        return x % a == 0;
    }
}