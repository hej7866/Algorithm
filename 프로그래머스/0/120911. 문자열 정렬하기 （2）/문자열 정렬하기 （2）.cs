using System;

public class Solution 
{
    public string solution(string my_string) 
    {
        string str = my_string.ToLower();
        char[] str_list = str.ToCharArray();
        Array.Sort(str_list);
        string result = new string(str_list);
        return result;
    }
}