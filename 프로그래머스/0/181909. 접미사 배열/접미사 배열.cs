using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string my_string) 
    {
        List<string> str = new List<string>();
        string[] answer = new string[my_string.Length];
        
        for (int i=0; i<=my_string.Length-1; i++) {
            str.Add(my_string.Substring(i, my_string.Length-i));   
        }
        str.Sort();
        answer = str.ToArray();
        return answer;
    }
}