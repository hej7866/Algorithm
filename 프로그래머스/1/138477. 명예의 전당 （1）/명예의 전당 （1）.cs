using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int k, int[] score) 
    {
        int day = score.Length;
        List<int> result = new List<int>();
        List<int> list = new List<int>();
        for(int i=0; i<day; i++)
        {
            if(list.Count < k)
            {
                list.Add(score[i]);
                list.Sort();
                result.Add(list[0]);
                continue;
            }
            
            int min = list.Min();
            if(list.Count == k)
            {
                if(score[i] > min)
                {
                    list.Remove(min);
                    list.Add(score[i]);
                    list.Sort();
                }
            }
            result.Add(list[0]);
        }
        return result.ToArray();
    }
}