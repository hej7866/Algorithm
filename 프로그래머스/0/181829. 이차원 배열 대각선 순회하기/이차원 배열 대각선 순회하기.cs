using System;

public class Solution 
{
    public int solution(int[,] board, int k) 
    {
        int sum = 0;
        for(int i=0; i<board.GetLength(0); i++)
        {
           for(int j=0; j<board.GetLength(1); j++)
           {
               if(i+j <= k)
               {
                   sum += board[i,j];
               }
           }
        }
        return sum;
    }
}