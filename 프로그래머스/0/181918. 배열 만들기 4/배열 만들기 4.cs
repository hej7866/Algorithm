using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr) 
    {
        List<int> stk_temp = new List<int>();
        int i = 0;
        
        
        while(i<arr.Length) {
            if(stk_temp.Count == 0) {
                stk_temp.Add(arr[i]);
                i++;
            }
            else {
                if(stk_temp[stk_temp.Count-1] < arr[i]) {
                    stk_temp.Add(arr[i]);
                    i++;
                }
                else if (stk_temp[stk_temp.Count-1] >= arr[i]) {
                    stk_temp.Remove(stk_temp[stk_temp.Count-1]);
                }
            }
        }
        int[] stk = stk_temp.ToArray();
        return stk;
    }
}