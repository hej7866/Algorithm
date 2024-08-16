using System;

public class Solution {
    public string solution(string my_string, int n) {
        string answer = "";
        
        int ml = my_string.Length;
        
        for (int i=ml-n; i<ml; i++) {
            answer += my_string[i].ToString();
        }
        return answer;
    }
}