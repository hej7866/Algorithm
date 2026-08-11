using System;

public class Solution 
{
    public int solution(int[,] sizes) 
    {
        int[] wallet = new int[2];
        
        // 가로가길고 세로가짧게 정렬
        for(int i=0; i<sizes.GetLength(0); i++)
        {
            if(sizes[i,0] < sizes[i,1])
            {
                int tmp = sizes[i,0];
                sizes[i,0] = sizes[i,1];
                sizes[i,1] = tmp;
            } 
        }
        wallet[0] = sizes[0,0];
        wallet[1] = sizes[0,1];
        
        for(int i=0; i<sizes.GetLength(0); i++)
        {
            if(wallet[0] < sizes[i,0])
            {
                wallet[0] = sizes[i,0];
            }
            
            if(wallet[1] < sizes[i,1])
            {
                wallet[1] = sizes[i,1];
            }
        }
        Console.WriteLine($"{wallet[0]}, {wallet[1]}");
        return wallet[0] * wallet[1];
    }
}