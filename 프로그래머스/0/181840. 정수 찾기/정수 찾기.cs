using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] num_list, int n)
    {
        List<int> numList = new List<int>(num_list);
        return numList.Contains(n) ? 1 : 0;
    }
}