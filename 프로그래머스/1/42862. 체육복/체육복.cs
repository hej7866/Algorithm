using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n, int[] lost, int[] reserve) 
    {
        List<int> lostList = new List<int>(lost);
        List<int> reserveList = new List<int>(reserve);
        
        lostList.Sort();
        reserveList.Sort();
        
        List<int> list = new List<int>();
        foreach(int r in reserveList)
        {
            if(lostList.Contains(r))
            {
                list.Add(r);
            }
        }
        
        foreach(int l in list)
        {
            lostList.Remove(l);
            reserveList.Remove(l);
        }
        
        foreach(int r in reserveList)
        {
            if(lostList.Contains(r - 1))
            {
                lostList.Remove(r - 1);
            }
            else if(lostList.Contains(r + 1))
            {
                lostList.Remove(r + 1);
            }
        }
        return n - lostList.Count;
    }
}