using System;
using System.Collections.Generic;

public class Solution 
{
    bool[] visited;
    HashSet<(int w, int h)> hash = new HashSet<(int, int)>();
    public int[] solution(int brown, int yellow) 
    {
        int[] result = new int[2];
        visited = new bool[brown];
        DFS(brown, yellow);
        foreach(var i in hash)
        {
            if(i.w >= i.h)
            {
                if((i.w - 2) * (i.h - 2) == yellow)
                {
                    Console.WriteLine(i);
                    result[0] = i.w;
                    result[1] = i.h;
                }
            }
        }
        return result;
    }
    
    void DFS(int b, int y)
    {
        int sum = b + y;
        for(int i=b; i>=1; i--)
        {
            if(sum % i == 0)
            {
                hash.Add((i, sum / i)); 
            }
        }
        
        
    }
}