using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, bool[] flag) 
    {
        List<int> arrList = new List<int>();
        
        for(int i=0; i<flag.Length; i++) {
            if(flag[i]) {
                for(int j=0; j<arr[i] * 2; j++){
                    arrList.Add(arr[i]);
                }
            }
            else {
                for(int j=0; j<arr[i]; j++){
                    arrList.RemoveAt(arrList.Count-1);
                }
            }
        }
        return arrList.ToArray();
    }
}