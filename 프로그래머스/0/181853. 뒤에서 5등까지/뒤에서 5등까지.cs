using System;
using System.Collections.Generic;
    
public class Solution 
{
    public int[] solution(int[] num_list) 
    {
        List<int> numList = new List<int>(num_list);
        numList.Sort();
        
        while(numList.Count != 5) {
            numList.RemoveAt(numList.Count-1);
        }
        return numList.ToArray();
    }
}