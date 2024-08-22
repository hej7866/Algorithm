using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string A, string B) 
    {
        char[] A_list = A.ToCharArray(); // A를 char[] 배열로 변환 
        char[] B_list = B.ToCharArray(); // B를 char[] 배열로 변환
        char[] temp_list = new char[A.Length]; // 임시 저장용 리스트인 temp_list선언, 크기는 A와 같다. 
        
        List<int> indexList = new List<int>(); // index를 담을 리스트 선언
        
        for (int i = 0; i < A.Length; i++){
            indexList.Add(i);
        }
        
        int[] rotate = new int[A.Length]; // 순환되는 index를 담을 배열 선언
        int count = 0; // 변환 횟수 count
        bool isPossible = false; // A가 B가 될 수 있는지 확인하는 bool 값
        
        while(count < A.Length) {
            int idx = 0;
            for (int i=0; i<A.Length; i++) {
                rotate[(i + count + 1) % A.Length] = indexList[idx]; // 순환하는 인덱스 01234 -> 40123 -> 34012
                idx++;
            }
            for(int j=0; j<A.Length; j++) {
                temp_list[j] = A_list[rotate[j]]; // temp_list에 순환한 인덱스에 해당되는 문자를 할당
            }
            count++; // 변환을 한번했으니 count증가
            string temp = new string(temp_list);
            if(temp == B) { // 만약 temp가 B와같으면
                isPossible = true; // 만들수있으므로 true로 만들어주고
                break; // 반복문 탈출
            } 
        }
        int answer = 0;
        int answerA = 0;
        int answerB = (isPossible) ? count : -1;
        return answer = (A != B) ? answerB : answerA; 
    }
}