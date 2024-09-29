using System;
using System.Linq;

public class Solution 
{
    public int solution(int[,] sizes) 
    {
        int wMax = 0;
        int hMax = 0;
        for(int i=0; i<sizes.GetLength(0); i++)
        {
            int w = sizes[i,0];
            int h = sizes[i,1];
            
            if(wMax < w)
            {
                wMax = w;
            }
            if(hMax < h)
            {
                hMax = h;
            }
        }
        
        int max = (wMax > hMax) ? wMax : hMax;
        
        int[] ans = new int[2];
        ans[0] = max;
        
        for(int i=0; i<sizes.GetLength(0); i++)
        {
            int w = sizes[i,0];
            int h = sizes[i,1];
            
            int tmp = (w > h) ? h : w;
            if(ans[1] < tmp)
            {             
                ans[1] = tmp;
            }
        }
        int area = 1;
        foreach(int num in ans)
        {
            area *= num;
        }
        
        return area;
    }
}