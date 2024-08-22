using System;

public class Solution 
{
    public string[] solution(string[] quiz) 
    {
        string[] answer = new string[quiz.Length]; // 결과를 담을 string배열 선언
        
        for(int i=0; i<quiz.Length; i++) {
            string[] arrQuiz = quiz[i].Split(' '); // quiz[i]를 공백을 기준으로 분리해서 배열을만듬
            // ex) "3 - 4 = -3"
            int a = Int32.Parse(arrQuiz[0]); // 3
            int b = Int32.Parse(arrQuiz[2]); // 4
            int c = Int32.Parse(arrQuiz[4]); // -3
            
            switch(arrQuiz[1]) { // switch 문으로 연산자에 대한 case분류
                case "+":
                    answer[i] = (a + b == c) ? "O" : "X";
                    break;
                case "-":
                    answer[i] = (a - b == c) ? "O" : "X";
                    break;
            }
        }
        return answer;
    }
}