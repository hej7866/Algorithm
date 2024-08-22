using System;

public class Solution 
{
    public string solution(string my_string, int num1, int num2) 
    {
        char[] str_list = my_string.ToCharArray();
        char temp = str_list[num1];
        str_list[num1] = str_list[num2];
        str_list[num2] = temp;
        string str = new string(str_list);
        return str;
    }
}