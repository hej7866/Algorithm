using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int a, int b) 
    {
        List<int> divNumA = new List<int>(); // a가 기약분수가 되는 과정을 담는 리스트
        List<int> divNumB = new List<int>(); // b가 기약분수가 되는 과정을 담는 리스트
        
        divNumA.Add(a); // 초기값 a대입
        divNumB.Add(b); // 초기값 b대입
        int index=0;
        for(int i=2; i<=divNumA[index]; i++) {
            // 만약 index번째의 divNumA와 divNumB의 요소의 값이 i로 나누었을때 모두 0이라면
            if(divNumA[index]%i == 0 && divNumB[index]%i == 0) {
                divNumA.Add(divNumA[index]/i); // 나눈 값을 리스트에 추가 ex [12, 4] (i=3일때 추가됨) 
                divNumB.Add(divNumB[index]/i); // 나눈 값을 리스트에 추가 ex [21, 7] (i=3일때 추가됨) 
                index++;
            }
        }
        List<int> div = new List<int>(); // 분모의 소인수를 담을 리스트
        int temp = divNumB[divNumB.Count-1]; // 임시저장용 변수 temp를 선언하고 초기값을 divNumB의 마지막 원소로 둔다.
        int k = 2; 
        while(temp>1) { // temp가 1이상일때까지만 반복
            while(temp % k == 0) { // temp를 k로 나눈 나머지가 0일때만 반복
                div.Add(k); // 위 조건을 만족하면 k값을 div에 추가
                temp /= k; // temp값을 temp를 k값으로 나눈값으로 변경 (#1. 20 -> 10 -> 5)
            }
            k++;
        }
        int answer = 1;
        // #1. div = {2, 2, 5}
        // #2. div = {2}
        // #3. div = {7}
        foreach(int num in div) { 
            if(num != 2 && num != 5) { //num의 값이 2와 5가 아니라면
                answer = 2; // answer에 2를대입
            } 
        }

        return answer;
    }
}