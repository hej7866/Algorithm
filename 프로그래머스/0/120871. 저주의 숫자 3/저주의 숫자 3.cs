using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n) 
    {
        List<int> threeX = new List<int>();
        
        int index = 1;
        threeX.Add(index);
        while(threeX.Count <= 100) 
        {
            if(threeX[threeX.Count - 1]%3 != 0 && !threeX[threeX.Count - 1].ToString().Contains("3")) 
            {    
                threeX.Add(index);
                index++;
            }
            if(threeX[threeX.Count - 1]%3 == 0 || threeX[threeX.Count - 1].ToString().Contains("3")) 
            {    
                threeX[threeX.Count - 1]++;
                index++;
            }
        }
        threeX.RemoveAt(0);
        return threeX[n-1];
        
    }
}