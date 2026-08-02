using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr) 
    {
        int min = arr[0];
        for(int i=0; i<arr.Length; i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
        }
        
        List<int> results = new List<int>();
        foreach(int n in arr)
        {
            if(n == min)
            {
                continue;
            }
            results.Add(n);
        }
        return results.Count > 0 ? results.ToArray() : new int[] {-1};
    }
}