using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, int k) 
    {
        List<int> arrList = new List<int>();
        for(int i=0; i<arr.Length; i++) {
            if(!arrList.Contains(arr[i]) && arrList.Count < k) {
                arrList.Add(arr[i]);   
            }
        }
        while(arrList.Count < k) {
            arrList.Add(-1);
        }
        
        return arrList.ToArray();
    }
}