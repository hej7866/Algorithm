using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int[] answer = new int[arr.Length];
        int row = queries.GetLength(0);
        int col = queries.GetLength(1);
        for (int idx=0; idx<arr.Length; idx++) {
            answer[idx] = arr[idx];
        }
        for (int r=0; r<row; r++) {
            int i = queries[r,0];
            int j = queries[r,1];
            int temp = answer[i];
            answer[i] = answer[j];
            answer[j] = temp;
        }
        return answer;
    }
}