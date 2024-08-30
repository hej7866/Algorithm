using System;

public class Solution 
{
    public string solution(string my_string, string letter) 
    {
        string result = "";
        for(int i=0; i<my_string.Length; i++)
        {
            if(my_string[i].ToString() != letter)
            {
                result += my_string[i].ToString(); 
            }
        }
        return result;
    }
}