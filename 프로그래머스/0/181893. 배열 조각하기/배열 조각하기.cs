using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, int[] query) 
    {
        List<int> arrList = new List<int>(arr);
        int count = 0;
        
        for (int i=0; i<query.Length; i++) {
            
            if(i%2 == 0) {
                while(arrList.Count > query[i]+1) {
                    arrList.RemoveAt(query[i]+1);
                }
            }
            
            else {
                while(count < query[i]) {
                    arrList.RemoveAt(0);
                    count++;
                }
                count = 0;
            }
        }
        
        int[] answer = arrList.ToArray();
        return answer;
    }
}