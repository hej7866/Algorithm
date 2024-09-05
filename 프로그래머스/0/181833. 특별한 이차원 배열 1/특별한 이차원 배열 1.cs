using System;

public class Solution 
{
    public int[,] solution(int n) 
    {
        int[,] nArr = new int[n,n];
        
        for(int i=0; i<n; i++)
        {
            nArr[i,i] = 1;
        }
        return nArr;
    }
}