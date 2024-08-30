using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string t, string p) 
    {
        List<long> tList = new List<long>();
        
        for(int i=0; i<=t.Length-p.Length; i++)
        {
            string tSubstring = t.Substring(i,p.Length);
            long tSub = long.Parse(tSubstring);
            tList.Add(tSub);
        }
        
        int count = 0;
        for(int i=0; i<tList.Count; i++)
        {
            if(long.Parse(p) >= tList[i])
            {
                count++;
            }
        }
        return count;
    }
}