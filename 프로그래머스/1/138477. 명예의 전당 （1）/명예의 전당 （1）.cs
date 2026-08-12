using System;
using System.Linq;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int k, int[] score) 
    {
        List<int> list = new List<int>();
        int[] result = new int[score.Length];
        
        for(int i=0; i<score.Length; i++)
        {
            if(list.Count < k)
            {
                list.Add(score[i]);
            }
            else if(list.Count == k)
            {
                if(list[0] < score[i])
                {
                    list[0] = score[i];
                }
            }
            list = list.OrderBy(x => x).ToList();
            result[i] = list[0];
        }
        return result;
    }
}