using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int rows, int columns, int[,] queries) 
    {
        int[][] matrix = new int[rows][];
        int next = 1;
        for(int i=0; i<rows; i++)
        {
            matrix[i] = new int[columns];
            for(int j=0; j<columns; j++)
            {
                matrix[i][j] = next++;    
            }
        }
        
        int length = queries.GetLength(0);
        List<int> result = new List<int>();
        for(int i=0; i<length; i++)
        {
            int startY = queries[i,0] - 1;
            int startX = queries[i,1] - 1;
            int endY = queries[i,2] - 1;
            int endX = queries[i,3] - 1;
            
            int currentY = startY;
            int currentX = startX;
            
            // 기존 값 담기
            List<int> list = new List<int>();
            for(int x=startX; x<=endX; x++)
            {
                currentX = x;
                list.Add(matrix[currentY][currentX]);
            }

            for(int y=startY + 1; y<=endY; y++)
            {
                currentY = y;
                list.Add(matrix[currentY][currentX]);
            }

            for(int x=endX - 1; x>=startX; x--)
            {
                currentX = x;
                list.Add(matrix[currentY][currentX]);
            }
  
            for(int y=endY - 1; y>startY; y--)
            {
                currentY = y;
                list.Add(matrix[currentY][currentX]);
            }
    
            // 회전
            currentY = startY;
            currentX = startX;
            List<int> newList = new List<int>();
            int idx = list.Count - 1;
            for(int x=startX; x<=endX; x++)
            {
                currentX = x;
                if(idx == list.Count)
                {
                    idx = 0;
                }
                matrix[currentY][currentX] = list[idx++];
                newList.Add(matrix[currentY][currentX]);
            }

            for(int y=startY + 1; y<=endY; y++)
            {
                currentY = y;
                if(idx == list.Count)
                {
                    idx = 0;
                }
                matrix[currentY][currentX] = list[idx++];
                newList.Add(matrix[currentY][currentX]);
            }

            for(int x=endX - 1; x>=startX; x--)
            {
                currentX = x;
                if(idx == list.Count)
                {
                    idx = 0;
                }
                matrix[currentY][currentX] = list[idx++];
                newList.Add(matrix[currentY][currentX]);
            }
  
            for(int y=endY - 1; y>startY; y--)
            {
                currentY = y;
                if(idx == list.Count)
                {
                    idx = 0;
                }
                matrix[currentY][currentX] = list[idx++];
                newList.Add(matrix[currentY][currentX]);
            }
            result.Add(newList.Min());
        }
        return result.ToArray();
    }
}