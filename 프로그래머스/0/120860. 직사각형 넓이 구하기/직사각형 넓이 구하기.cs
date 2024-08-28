using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[,] dots) 
    {
        List<int> xPos = new List<int>();
        List<int> yPos = new List<int>();
        for(int i=0; i<dots.GetLength(0); i++)
        {
            xPos.Add(dots[i,0]);
        }
        for(int i=0; i<dots.GetLength(0); i++)
        {
            yPos.Add(dots[i,1]);
        }
        xPos.Sort();
        yPos.Sort();
        
        return Math.Abs(xPos[1] - xPos[2]) * Math.Abs(yPos[1] - yPos[2]);
    }
}