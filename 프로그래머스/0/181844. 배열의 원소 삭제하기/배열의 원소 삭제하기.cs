using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] arr, int[] delete_list) 
    {
        List<int> arrList = new List<int>(arr);
        
        foreach(int num in delete_list)
        {
            for(int i=0; i < arrList.Count; i++)
            {
                if(arrList[i] == num)
                {
                    arrList.Remove(num);
                }
            }
        }
        return arrList.ToArray();
    }
}