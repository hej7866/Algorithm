using System;
using System.Collections.Generic;
using System.Linq;

        
public class Solution 
{
    public int solution(string[] strArr) 
    {
        // strArr의 각각의 요소에 담긴 문자열의 길이를 요소로할 리스트를 선언
        List<int> numList = new List<int>();
        // 리스트에 strArr[i]의 길이를 하나씩 하나씩 할당
        for(int i=0; i<strArr.Length; i++) {
            numList.Add(strArr[i].ToString().Length);
        }
        numList.Sort(); // 리스트 정렬
        
        List<int> countList = new List<int>();
        int count = 0;
        int previousNum = -1;
        foreach (int num in numList) 
        {
            if (num == previousNum) {
                count++;
            } 
            else {
                if (previousNum != -1) {
                    countList.Add(count);
                }
                previousNum = num;
                count = 1;
            }
        }
        
        // 마지막 빈도수 추가
        if (previousNum != -1) 
        {
             countList.Add(count);
        }
        
        countList.Sort();

        // 결과를 배열로 변환
        return countList[countList.Count - 1];
    }     
}