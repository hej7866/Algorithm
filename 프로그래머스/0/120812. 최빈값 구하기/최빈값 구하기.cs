using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int solution(int[] array) 
    {
        int[] arrList = new int[1000]; // 1000개의 길이를 가진 배열 만들기
        for(int i=0; i<array.Length; i++)
        {
            arrList[array[i]]++; // arrList의 array[i]번째 인덱스 값을 1씩 올림 (숫자가 등장하는 횟수 세기)
        }
        
        int max = arrList.Max(); // arrList의 최대값
        int count = 0; // 최빈값이 여러개인지 체크하는 변수
        int mostCountValue = 0; // 최빈값을 담을 변수
        for(int i=0; i<arrList.Length; i++)
        {
            if(arrList[i] == max) // arrList의 i번째 인덱스가 max값과 같은경우
            {
                count++; // count를 하나 를리고
                mostCountValue = i; // i값을 담는다.
            }
        }
        

        int answer = (count > 1) ? -1 : mostCountValue;
        return answer;
    }
}