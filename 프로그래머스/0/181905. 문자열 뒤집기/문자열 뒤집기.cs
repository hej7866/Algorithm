using System;

public class Solution {
    public string solution(string my_string, int s, int e) {
        string answer = "";
        char[] temp = my_string.ToCharArray();
            
        Array.Reverse(temp, s, e - s + 1);
        answer = new string(temp);
        return answer;
    }
}