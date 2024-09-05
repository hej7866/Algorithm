using System;

public class Solution 
{
    public int[,] solution(int[,] arr) 
    {
        int arrRow = arr.GetLength(0);
        int arrCol = arr.GetLength(1);
                
        int row = 0;
        int col = 0;
        if(arrRow > arrCol)
        {
            row = arrRow;
            col = row;
        }
        else if(arrRow < arrCol)
        {
            col = arrCol;
            row = col;
        }
        else 
        {
            row = arrRow;
            col = arrCol;
        }
        
        int[,] arrSquare = new int[row,col];
        
        for(int i=0; i<arrRow; i++)
        {
            for(int j=0; j<arrCol; j++)
            {
                arrSquare[i,j] = arr[i,j];
            }
        }
        return arrSquare;
    }
}