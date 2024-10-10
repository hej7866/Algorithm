using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(long n) 
    {
        string strN = n.ToString();
        
        List<int> list = new List<int>();
        for(int i=strN.Length-1; i>=0; i--)
        {
            list.Add(strN[i] - '0');
        }
        return list.ToArray();
    }
}