using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string my_string) 
    {
        List<char> rvStr = new List<char>(); 

        for(int i=my_string.Length-1; i>=0; i--)
        {
            rvStr.Add(my_string[i]);
        }
        
        char[] rvArr = rvStr.ToArray();
        string reverse = new string(rvArr);
        return reverse;
    }
}