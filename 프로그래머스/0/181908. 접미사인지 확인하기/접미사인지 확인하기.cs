using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string my_string, string is_suffix) 
    {
        int answer = 0;
        
        List<string> suffix = new List<string>();
        int ml = my_string.Length;
        string[] Mystr = new String[ml];
        
        
        for (int i=0; i<=ml; i++) {
            suffix.Add(my_string.Substring(i,ml-i));
        }
        
        Mystr = suffix.ToArray();
        
        foreach(string s in Mystr) {
            if(s == is_suffix) {
                answer = 1;
            }
        }
        return answer;
    }
}