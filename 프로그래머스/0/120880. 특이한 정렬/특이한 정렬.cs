using System;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] numlist, int n) 
    {
        var sortedNumbers = numlist.OrderBy(x => Math.Abs(x-n))
                                   .ThenByDescending(x => x)                       
                                   .ToArray();
        return sortedNumbers;
    }
}