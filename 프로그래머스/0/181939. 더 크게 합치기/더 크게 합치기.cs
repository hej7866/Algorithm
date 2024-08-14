using System;

public class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        // 1.
        string a1 = a.ToString();
        string b1 = b.ToString();
        
        // 2.
        int answer1 = int.Parse(a1+b1);
        int answer2 = int.Parse(b1+a1);
        
        // 3.
        if(answer1 >= answer2) {
            answer = answer1;
        }
        else {
            answer = answer2;
        }
        return answer;
    }
}