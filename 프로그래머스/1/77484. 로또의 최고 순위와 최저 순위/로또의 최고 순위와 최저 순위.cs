using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(int[] lottos, int[] win_nums) 
    {
    int high_count = 0;
    int low_count = 0;
        
    foreach(int w in win_nums)
    {
        for(int i=0; i<lottos.Length; i++)
        {
            if(lottos[i] == w)
            {
                high_count++;
                low_count++;
            }
        }
    }
    
    foreach(int n in lottos)
    {
        if(n == 0)
        {
            high_count++;
        }
    }
    
    Dictionary<int,int> dic = new Dictionary<int,int>()
    {
        {0, 6},
        {1, 6},
        {2, 5},
        {3, 4},
        {4, 3},
        {5, 2},
        {6, 1},
        
    };
    int[] result = new int[2];
    result[0] = dic[high_count];
    result[1] = dic[low_count];
    return result;
    }
}