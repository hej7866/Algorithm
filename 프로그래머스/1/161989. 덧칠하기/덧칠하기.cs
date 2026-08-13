using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n, int m, int[] section) 
    {
        int right = 0;
        int count = 0;
        for(int i=0; i<section.Length; i++)
        {
            if(section[i] < right)
            {
                continue;
            }
            right = section[i] + m;
            count++;
        }
        return count;
       
        
    }
}