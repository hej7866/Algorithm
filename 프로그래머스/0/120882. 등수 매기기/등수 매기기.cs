using System;

public class Solution 
{
    public int[] solution(int[,] score) 
    {
        int row = score.GetLength(0);
        double[] avg = new double[row];
        for(int r=0; r<row; r++) {
            avg[r] = (double)(score[r,0] + score[r,1]) / 2;    
        }
        
        int[] rank = new int[row];
        
        for(int i=0; i<rank.Length; i++) {
           rank[i] = 1;
        }
        
        for(int i=0; i<avg.Length; i++) {
            for(int j=0; j<avg.Length; j++) {
                if(avg[i] < avg[j]) {
                    rank[i]++;
                }              
            }
        }
        return rank;

    }
}