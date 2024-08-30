using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] num_list) 
    {
        int nl = num_list.Length;
        List<int> reverseList = new List<int>(num_list);
        reverseList.Reverse();
        
        return reverseList.ToArray();
        
    }
}