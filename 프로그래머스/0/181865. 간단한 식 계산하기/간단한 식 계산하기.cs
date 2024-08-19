using System;

public class Solution {
    public int solution(string binomial) {
        string[] bin = binomial.Split(' ');
        int answer = 0;
        switch(bin[1]){
            case "+":
               answer = Int32.Parse(bin[0]) + Int32.Parse(bin[2]);
                break;
            case "-":
                answer = Int32.Parse(bin[0]) - Int32.Parse(bin[2]);
                break;
            case "*":
                answer = Int32.Parse(bin[0]) * Int32.Parse(bin[2]);
                break;         
        }
        return answer;
    }
}