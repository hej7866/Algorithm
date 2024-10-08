using System;

public class Solution 
{
    public string solution(string phone_number) 
    {
        string str1 = "";
        for(int i=0; i<phone_number.Length - 4; i++)
        {
            str1 += "*";
        }
        
        string str2 = phone_number.Substring(phone_number.Length - 4,4);
        
        Console.Write("{0} {1}", str1, str2);
        return str1 + str2;
    }
}