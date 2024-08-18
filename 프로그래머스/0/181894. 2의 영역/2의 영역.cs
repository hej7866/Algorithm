using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr) 
    {
        List<int> temp = new List<int>(); // arr에서 2가 등장하는 idx를 담을 리스트
        List<int> arrList = new List<int>(); // 위에서 추출한 idx를 통하여 result값을 담을 배열
        int count = 0;
        
        // 2가 등장하는 idx를 추출하는 과정
        for (int i=0; i<arr.Length; i++) {
            if(arr[i] == 2) {
                temp.Add(i);
                count++; // 이 값을통해서 2가들어있는 idx가 몇개있는지 카운트 할 수 있다.
            }
        }
        
        // 만약 count가 0이라면 결과값에 -1을 할당
        if (count == 0) {
            arrList.Add(-1);
        }
        // 그렇지 않다면 다음을 실행
        else {
            for(int i=temp[0]; i<=temp[count-1]; i++) {
                arrList.Add(arr[i]);
            }
        }
        
        int[] answer = arrList.ToArray(); // 리스트를 배열로 변환
        return answer;
    }
}