using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(int[] array, int height) 
    {
        
        var tollerList = array.Where(w => w > height)
                                .ToArray();
                                
        
        return tollerList.Length;
    }
}