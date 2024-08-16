using System;

public class Solution 
{
    public string solution(string my_string, int m, int c) 
    {
        string answer = "";
        
        for(int i=0; i<my_string.Length; i++) {
            if(i%m == c-1) {
                answer += my_string[i].ToString();
            }
        }
        return answer;
    }
}