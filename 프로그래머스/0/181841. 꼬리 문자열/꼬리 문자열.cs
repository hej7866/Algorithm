using System;

public class Solution 
{
    public string solution(string[] str_list, string ex) 
    {
        string connectStr = "";
        
        for(int i=0; i<str_list.Length; i++)
        {
            if(str_list[i].Contains(ex))
            {
                continue;
            }
            connectStr += str_list[i];
        }
        return connectStr;
    }
}