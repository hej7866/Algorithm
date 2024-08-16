using System;

public class Solution 
{
    public string solution(string my_string, int n) 
    {
        string answer = "";
        string str = "";
        
        for (int i=0; i<n; i++) {
            str += my_string[i].ToString();
        }
        answer = str;
        return answer;
    }
}