using System;

public class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        string a1 = a.ToString();
        string b1 = b.ToString();
        
        int value1 = int.Parse(a1 + b1);
        int value2 = 2 * a * b;
        
        if (value1 >= value2) {
            answer = value1;
        }
        else {
            answer = value2;
        }
        return answer;
    }
}