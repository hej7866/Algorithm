using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int[] array, int n) 
    {
        List<int> absList = new List<int>(); // n - array[i] 의 절대값을 담을 리스트 
        
        Array.Sort(array);
        for(int i=0; i<array.Length; i++) {
            absList.Add(Math.Abs(n-array[i])); // absList에  n - array[i]의 절대값을 추가한다.
        }
        
        int index = 0; // absList 가 최소값을 가지는 index를 담을 변수 선언
        for(int j=0; j<absList.Count; j++) {
            if(absList[j] == absList.ToArray().Min()) { // absList[j]가 absList의 최소값과 같다면
                index = j; // 그 j값을 index에 담는다.
                break;
            }
        }
        return array[index];
    }
}