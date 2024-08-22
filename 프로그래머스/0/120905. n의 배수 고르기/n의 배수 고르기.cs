using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int n, int[] numlist) 
    {
        List<int> resultList = new List<int>();
        
        for(int i=0; i<numlist.Length; i++) {
            if(numlist[i]%n == 0) {
                resultList.Add(numlist[i]);
            }
        }
        return resultList.ToArray();
    }
}