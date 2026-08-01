using System;
using System.Collections.Generic;
using System.Text;

public class Solution 
{
    public string solution(string s) 
    {
        List<string> strings = new List<string>(); 
        
        string temp = "";
        foreach(char c in s)
        {
            if(c != ' ')
            {
                temp += c;
            }
            else
            {
                strings.Add(temp);
                temp = "";
            }
        }
        strings.Add(temp);
        
        List<string> results = new List<string>();
        foreach(string str in strings)
        {
            char[] arr = str.ToCharArray();
            for(int i = 0; i < arr.Length; i++)
            {
                arr[i] = (i % 2 == 0) ? char.ToUpper(arr[i]) : char.ToLower(arr[i]);
            }
            results.Add(new string(arr));
        }
        
        return string.Join(" ", results);
    }
}