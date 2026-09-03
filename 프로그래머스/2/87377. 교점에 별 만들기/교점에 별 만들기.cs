using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(int[,] line) 
    {
        List<List<int>> lineList = new List<List<int>>();
        for(int i=0; i<line.GetLength(0); i++)
        {
            List<int> list = new List<int>(); 
            for(int j=0; j<3; j++)
            {
                list.Add(line[i,j]);
            }
            lineList.Add(list);
        }
        
        HashSet<(long x, long y)> crossHash = new HashSet<(long, long)>();
        for(int i=0; i<lineList.Count - 1; i++)
        {
            for(int j=i+1; j<lineList.Count; j++)
            {
                if(Solve(lineList[i].ToArray(), lineList[j].ToArray()))
                {
                    crossHash.Add(Solve2(lineList[i].ToArray(), lineList[j].ToArray()));
                }
            }
        }
        long maxX = long.MinValue;
        long minX = long.MaxValue;
        long maxY = long.MinValue;
        long minY = long.MaxValue;
        
        foreach(var i in crossHash)
        {
            if(maxX < i.x) maxX = i.x;
            if(minX > i.x) minX = i.x;
            if(maxY < i.y) maxY = i.y;
            if(minY > i.y) minY = i.y;
        }
        int width = (int)(maxX - minX + 1);   // 9
        int height = (int)(maxY - minY + 1); // 9
        
        char[][] board = new char[height][];
        for (int i = 0; i < height; i++)
        {
            board[i] = new string('.', width).ToCharArray();
        }

        foreach (var point in crossHash)
        {
            int row = (int)(maxY - point.y);
            int column = (int)(point.x - minX);
            board[row][column] = '*';
        }

        string[] result = new string[height];

        for (int i = 0; i < height; i++)
        {
            result[i] = new string(board[i]);
        }

        return result;
    }
    
    bool Solve(int[] a, int[] b)
    {
        long denominator = (long)a[0] * b[1] - (long)a[1] * b[0];

        if (denominator == 0)
            return false;

        long xNumerator = (long)a[1] * b[2] - (long)a[2] * b[1];
        long yNumerator = (long)a[2] * b[0] - (long)a[0] * b[2];

        if (xNumerator % denominator != 0) return false;
        if (yNumerator % denominator != 0) return false;

        return true;
    }
    
    (long, long) Solve2(int[] a, int[] b)
    {
        long denominator = (long)a[0] * b[1] - (long)a[1] * b[0];
        long x = ((long)a[1] * b[2] - (long)a[2] * b[1]) / denominator;
        long y = ((long)a[2] * b[0] - (long)a[0] * b[2]) / denominator;
        return (x, y);
    }
}