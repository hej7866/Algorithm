using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr) 
    {
        List<int> stkList = new List<int>();
        int i = 0;
        
        while(i<arr.Length) {
            if(stkList.Count == 0) {
                stkList.Add(arr[i]);
                i++;
            }
            else if(stkList.Count != 0 && stkList[stkList.Count - 1] == arr[i]) {
                stkList.RemoveAt(stkList.Count - 1);
                i++;
            }
            else if (stkList.Count != 0 && stkList[stkList.Count - 1] != arr[i]) {
                stkList.Add(arr[i]);
                i++;
            }
        }
        if (stkList.Count == 0) {
            stkList.Add(-1);
        }
        return stkList.ToArray();
    }
}