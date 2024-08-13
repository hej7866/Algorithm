using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int[] answer = new int[queries.GetLength(0)];
        for (int i=0; i<queries.GetLength(0); i++) {
            int s = queries[i,0];
            int e = queries[i,1];
            int k = queries[i,2];
            int save = -1;
            
            for (int j=s; j<=e; j++) {
                if (arr[j] > k) {
                    if (save == -1) {
                        save = arr[j];
                    }
                    else if (save > arr[j]) {
                        save = arr[j];
                    }
                }
            }
        answer[i] = save;
        }
    return answer;
    }
}
