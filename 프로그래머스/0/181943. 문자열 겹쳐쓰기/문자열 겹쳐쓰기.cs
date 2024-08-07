using System;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) {
        string answer = "";
        for (int i=0; i<my_string.Length; i++) {
            if (i<s || i>s+overwrite_string.Length-1) {
                answer += my_string[i];   
            }
            else {
                answer += overwrite_string[i-s];
            }
        }

        return answer;
    }
}