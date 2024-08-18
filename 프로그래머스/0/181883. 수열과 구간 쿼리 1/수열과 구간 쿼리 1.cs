using System;

public class Solution 
{
    public int[] solution(int[] arr, int[,] queries) 
    {
        int row = queries.GetLength(0);
        
        for(int r=0; r<row; r++) {
            int s = queries[r,0];
            int e = queries[r,1];
            
            for (int i=s; i<=e; i++) {
                arr[i]++;
            }
        }
        return arr;
    }
}