using System;
public class Solution 
{
    int zeroCount = 0;
    int oneCount = 0;

    public int[] solution(int[,] arr) 
    {
        Compress(arr, 0, 0, arr.GetLength(0));
        return new int[] { zeroCount, oneCount };
    }

    void Compress(int[,] arr, int row, int col, int size)
    {
        if(IsSame(arr, row, col, size))
        {
            if(arr[row,col] == 0) zeroCount++;
            else oneCount++;
            return;
        }

        int half = size / 2;
        Compress(arr, row, col, half);               // 왼쪽 위
        Compress(arr, row, col + half, half);         // 오른쪽 위
        Compress(arr, row + half, col, half);          // 왼쪽 아래
        Compress(arr, row + half, col + half, half);   // 오른쪽 아래
    }

    bool IsSame(int[,] arr, int row, int col, int size)
    {
        int first = arr[row,col];
        for(int i = row; i < row + size; i++)
        {
            for(int j = col; j < col + size; j++)
            {
                if(arr[i,j] != first) return false;
            }
        }
        return true;
    }
}