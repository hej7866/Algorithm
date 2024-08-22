using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string my_string) 
    {   // ex) "3 + 5 + 7 - 13" : result : 2
        string[] operation = my_string.Split(' '); // ["3","+","5","+","7","-","13"]
        
        List<int> numList = new List<int>(); // 숫자만 담을 리스트
        List<string> operatorList = new List<string>(); // 연산자만 담을 리스트
        for(int i=0; i<operation.Length; i++) {
            if(i%2 == 0) { 
                numList.Add(Int32.Parse(operation[i])); // 짝수인 항 정수형으로 바꿔서 추가 [3,5,7,13]
            }
            else {
                operatorList.Add(operation[i].ToString()); // 홀수인 항 문자열형으로 바꿔서 추가 ["+","+","-"]
            }
        }
        int result = numList[0]; // 초기값 numList의 첫번째 값으로 설정 3
        int idx = 0;
        while (idx < operatorList.Count) {
            switch(operatorList[idx]) { // idx : 0 -> "+", idx : 1 -> "+", idx : 2 -> "-"
                case "+":
                    result += numList[idx + 1]; // idx : 0 -> 5, idx : 1 -> 7, idx : 2 -> 13
                    break;
                case "-":
                    result -= numList[idx + 1]; // idx : 0 -> 5, idx : 1 -> 7, idx : 2 -> 13
                    break;   
            }
            idx++;
        }
        
        return result;
    }
}