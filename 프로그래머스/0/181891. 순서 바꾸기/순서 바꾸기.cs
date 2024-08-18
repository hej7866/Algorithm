using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] num_list, int n) 
    {
        List<int> numList = new List<int>();
        for(int i=n; i<num_list.Length; i++) {
            numList.Add(num_list[i]);
        }
        for (int i=0; i<n; i++) {
            numList.Add(num_list[i]);
        }
        
        int[] answer = numList.ToArray();
        return answer;
    }
}