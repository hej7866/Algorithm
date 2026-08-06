using System;

public class Solution 
{
    public string solution(string phone_number) 
    {
        char[] p = phone_number.ToCharArray();
        for(int i=0; i<p.Length-4; i++)
        {
            p[i] = '*';
        }
        return new string(p);
    }
}