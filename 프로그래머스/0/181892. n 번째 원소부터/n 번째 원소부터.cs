using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] num_list, int n) 
    {
        List<int> numList = new List<int>();
        
        for(int i=n-1; i<num_list.Length; i++) {
            numList.Add(num_list[i]);
        }
        
        int[] answer = numList.ToArray();
        return answer;
    }
}