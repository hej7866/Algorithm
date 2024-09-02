using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int[] array, int n) 
    {
        var count = array.Where(w => w == n)
                         .ToArray();
        return count.Length;
    }
}