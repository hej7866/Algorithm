using System;

public class Solution 
{
    public int[] solution(string[] wallpaper) 
    {
        int minX = wallpaper[0].Length;
        int minY = wallpaper.Length;
        int maxX = 0;
        int maxY = 0;
        
        for(int i=0; i<wallpaper.Length; i++)
        {
            string str = wallpaper[i];
            for(int j=0; j<str.Length; j++)
            {
                if(str[j] == '#')
                {
                    if(minX > j)
                    {
                        minX = j;
                    }
                    if(minY > i)
                    {
                        minY = i;
                    }
                    if(maxX < j)
                    {
                        maxX = j;
                    }
                    if(maxY < i)
                    {
                        maxY = i;
                    }
                }
            }
        }
        
        int[] result = new int[]
        {
            minY, minX, maxY + 1, maxX + 1
        };
        return result;
    }
}