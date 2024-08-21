using System;

public class Solution 
{
    public int[] solution(int num, int total) 
    {
        int[] num_list = new int[num]; // 결과를 담을 크기가 num인 배열 선언
        int a = -1000;                 // 초기값을 넉넉하게 -1000으로 설정
        int numSum = 0;                // 연속된 수 num개를 더한 값을 담을 변수
        
        while(true) {                  // 원하는 결과가 나올때까지 일단 무한 반복 
            int temp = a;              // 임시저장용 변수 temp에 a를 넣어놓기 처음엔 -1000이 들어갈거임.           
            for(int i=0; i<num; i++) { 
                num_list[i] = temp;    // num_list에 연속된 수를 넣고 
                numSum += num_list[i]; // numSum에 그 연속된 수를 더하는 과정을 담은
                temp++;                // 코드이다.
            }
            if(numSum != total) {     // 위 과정을 거쳤음에도 numSum이 total과 같지않으면 
                a++;                  // a를 1만큼 올리고
                numSum = 0;           // numSum을 0으로 초기화한다음
                continue;             // 다시 while문으로 돌아간다.
            }
            else if (numSum == total) { 
                break; // 만약 조건을 만족한다면 while문을 탈출한다.
            }
        }
        return num_list;
    }
}

/* 
using System;

public class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        bool isEven = num % 2 == 0;
        int quotient = total / num;

        if (!isEven) { // 홀수면 가운데 들어가는 숫자가 몫
            for (int i = 0; i < answer.Length; i++)
                answer[i] = quotient - (num / 2) + i;
        } else {
            for (int i = 0; i < answer.Length; i++)
                answer[i] = quotient - (num / 2) + i + 1;
        }
        return answer;
    }
} 
*/