using System;
using System.Collections.Generic;
public class Solution 
{
    public int[] solution(int[] num_list, int n) 
    {
        List<int> numList = new List<int>();
        
        for (int i=0; i<num_list.Length; i = i + n) {
            numList.Add(num_list[i]);
        }
        
        return numList.ToArray();
    }
}