using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] arr, int k) 
    {
        int[] arrList = new int[arr.Length];
        if(k%2 == 1)
        {
            arrList = arr.Select(w => w * k)
                         .ToArray();
        }
        else if(k%2 == 0)
        {
            arrList = arr.Select(w => w + k)
                         .ToArray();
        }
        return arrList;
    }
}