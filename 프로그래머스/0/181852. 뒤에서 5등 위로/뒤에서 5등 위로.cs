using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] num_list) 
    {
        Array.Sort(num_list);
        List<int> removeList = new List<int>(num_list);
        for(int i=0; i<5; i++)
        {
            removeList.RemoveAt(0);
        }
        return removeList.ToArray();
    }
}