using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, int[,] intervals) 
    {
        List<int> arrList = new List<int>();
        int row = intervals.GetLength(0);
        
        for (int r=0; r<row; r++) {
            for (int c=intervals[r,0]; c<=intervals[r,1]; c++) {
                arrList.Add(arr[c]);
            }
        }
        
        int[] answer = arrList.ToArray();
        return answer;
    }
}