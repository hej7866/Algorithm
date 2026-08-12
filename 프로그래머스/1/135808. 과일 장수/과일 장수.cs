using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int k, int m, int[] score) 
    {
        Array.Sort(score);
        int count = 0;
        List<List<int>> boxList = new List<List<int>>();
        List<int> tmpList = new List<int>();
        for(int i=score.Length - 1; i>=0; i--)
        {
            tmpList.Add(score[i]);
            count++;
            if(count == m)
            {
                boxList.Add(tmpList);
                tmpList = new List<int>();
                count = 0;
            }
        }
        
        int s = 0;
        foreach(List<int> list in boxList)
        {
            s += list[list.Count - 1] * m;
        }
        return s;
    }
}