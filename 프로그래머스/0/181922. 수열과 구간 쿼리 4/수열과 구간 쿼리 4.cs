using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int[] answer = new int[arr.Length];
        for (int r=0; r<queries.GetLength(0); r++) {
            int s = queries[r,0];
            int e = queries[r,1];
            int k = queries[r,2];
            
            for (int i=s; i<=e; i++) {
                if(i%k == 0) {
                    arr[i] += 1;
                }
            }
        }
        
        return arr;
    }
}