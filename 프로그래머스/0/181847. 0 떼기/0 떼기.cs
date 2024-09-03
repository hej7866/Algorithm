using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string n_str) 
    {
        List<char> nstrList = new List<char>();
        int count = 0;
        for(int i=0 ; i<n_str.Length; i++)
        {
            if(n_str[i] != '0')
            {
                count++;
            }
            
            if(count >= 1)
            {
                nstrList.Add(n_str[i]);
            }
        }
        string result = new string(nstrList.ToArray());
        return result;
    }
}