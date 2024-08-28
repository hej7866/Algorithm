using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int n) 
    {
        List<int> pfList = new List<int>();
        
        int i = 2;
        while(i <= n)
        {
            bool pfCheck = false;
            if(n%i == 0)
            {
                pfCheck = true;
                n = n / i;
                pfList.Add(i);
            }
            if(pfCheck) 
            {
                continue;    
            }
            else if(!pfCheck) 
            {
                i++;  
            }
        }
        
        int[] primefactorList =  pfList.GroupBy(x => x)
                                       .Select(x => x.Key)
                                       .ToArray();
        return primefactorList;
    }
}