using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] numbers) 
    {
        HashSet<int> numSet = new HashSet<int>();
        
        for(int i=0; i<numbers.Length - 1; i++)
        {
            for(int j = i+1; j<numbers.Length; j++)
            {
                numSet.Add(numbers[i] + numbers[j]);
            }
        }
        
        List<int> result = new List<int>();
        foreach(int n in numSet)
        {
            result.Add(n);
        }
        result.Sort();
        return result.ToArray();
    }
}