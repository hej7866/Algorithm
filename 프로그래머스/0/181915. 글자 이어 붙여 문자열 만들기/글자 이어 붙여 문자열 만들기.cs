using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string my_string, int[] index_list) 
    {
        string answer = "";
        foreach (int index in index_list) {
            answer += my_string[index];
        }
        return answer;
    }
}