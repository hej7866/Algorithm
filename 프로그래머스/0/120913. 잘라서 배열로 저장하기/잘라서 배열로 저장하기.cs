using System;
using System.Collections.Generic;
    
public class Solution 
{
    public string[] solution(string my_str, int n) 
    {  
        List<char> strList = new List<char>();
        List<string> mystr = new List<string>();

        for(int i=0; i<my_str.Length; i++) {
            strList.Add(my_str[i]);
            if (strList.Count == n || i == my_str.Length - 1) {
                char[] str_list = strList.ToArray();
                string temp = new string(str_list);
                mystr.Add(temp);
                strList.Clear();
            }
        }
        return mystr.ToArray();
    }
}