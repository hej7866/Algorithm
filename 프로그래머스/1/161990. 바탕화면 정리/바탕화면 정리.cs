using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(string[] wallpaper) 
    {
        int wpRow = wallpaper.Length;
        int wpCol = wallpaper[0].Length;
        
        // wallpaper을 2차원 배열로 담는 과정
        string[,] wpList = new string[wpRow,wpCol];
        for(int i=0; i<wpRow; i++)
        {
            string temp = wallpaper[i];
            for(int j=0; j<wpCol; j++)
            {
                wpList[i,j] = temp[j].ToString();
            }
        }
        

        List<int> sharpRowList = new List<int>();
        List<int> sharpColList = new List<int>();
        for(int i=0; i<wpRow; i++)
        {
            for(int j=0; j<wpCol; j++)
            {
                if(wpList[i,j] == "#")
                {
                    sharpRowList.Add(i);
                    sharpColList.Add(j);
                }
            }
        }
        int lux = sharpRowList.Min();
        int luy = sharpColList.Min();
        int rdx = sharpRowList.Max() + 1;
        int rdy = sharpColList.Max() + 1;
        
        int[] dragArea = new int[] { lux, luy, rdx, rdy };
        
        return dragArea;
    }
}