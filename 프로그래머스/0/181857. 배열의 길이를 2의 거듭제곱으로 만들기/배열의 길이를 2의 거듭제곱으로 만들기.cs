using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr) 
    {
        List<int> arrList = new List<int>(arr);

        while((arrList.Count & (arrList.Count - 1)) != 0) {
            arrList.Add(0);
        }
        return arrList.ToArray();
    }
}