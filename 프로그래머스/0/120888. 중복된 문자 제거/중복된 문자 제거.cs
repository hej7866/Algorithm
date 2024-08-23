using System;

public class Solution 
{
    public string solution(string my_string) 
    {
        string str = "";
        for(int i=0; i<my_string.Length; i++) {
            if(!str.Contains(my_string[i])) {
                str += my_string[i].ToString();
            } 
        }
        return str;
    }
}