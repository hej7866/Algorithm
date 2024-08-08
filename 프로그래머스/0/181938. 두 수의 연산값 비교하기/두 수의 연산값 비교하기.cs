using System;

public class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        int value1 = int.Parse(a.ToString() + b.ToString());
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