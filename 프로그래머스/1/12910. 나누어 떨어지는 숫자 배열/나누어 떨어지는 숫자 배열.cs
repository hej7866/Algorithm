using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, int divisor) 
    {
        List<int> list = new List<int>();
        foreach(int i in arr)
        {
            if(i%divisor == 0)
            {
                list.Add(i);
            }
        }
        list.Sort();
        if(list.Count == 0)
        {
            list.Add(-1);
        }
        return list.ToArray();
    }
}