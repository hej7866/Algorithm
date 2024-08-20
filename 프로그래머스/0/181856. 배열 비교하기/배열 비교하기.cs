using System;

public class Solution 
{
    public int solution(int[] arr1, int[] arr2) 
    {
        int answer = 0;
        int arr1Sum = 0; // arr1을 모두 더하기 위한 변수 선언
        int arr2Sum = 0; // arr2을 모두 더하기 위한 변수 선언
        
        for(int i=0; i<arr1.Length; i++) {
            arr1Sum += arr1[i]; // arr1을 모두 더하기
        }
        for(int i=0; i<arr2.Length; i++) {
            arr2Sum += arr2[i]; // arr2을 모두 더하기
        } 
        
        // 만약 arr1의길이가 arr2의 길이보다 길면 answer에 1을 그렇지않으면 -1을 할당
        answer = (arr1.Length > arr2.Length) ? 1 : -1; 
        
        // 만약 arr1의길이와 arr2의 길이가 같을때 
        // arr1sum의 크기가 arr2sum의 크기보다 크면 answer에 1을 그렇지않으면 -1을 할당
        if (arr1.Length == arr2.Length) {
            answer = (arr1Sum > arr2Sum) ? 1 : -1;
        }
        
        // 만약 arr1의길이와 arr2의 길이가 같으면서 arr1sum의 크키와 arr2sum의 크기가 같으면 answer에 0을 할당
        if (arr1.Length == arr2.Length && arr1Sum == arr2Sum) {
            answer = 0;
        }   
 
        return answer;
    }
}