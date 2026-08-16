using System;
using System.Collections.Generic;

class Solution 
{
    public int solution(int n) 
    {
        Stack<int> s = new Stack<int>();
        int count = 0;
        int num = n;
        while(num > 0)
        {
            int remainder = num % 2;   // 나머지 (0 또는 1)
            if(remainder == 1)
            {
                count++;
            }
            num /= 2;   
        }

        int count2 = 0;
        int i = 1;
        int num2 = n + i;
        while(count2 != count)
        {
            count2 = 0;
            while(num2 > 0)
            {
                int remainder = num2 % 2;   // 나머지 (0 또는 1)
                if(remainder == 1)
                {
                    count2++;
                }
                num2 /= 2;   
            }
            i++;
            num2 = n + i; 
        }
        
       
        return n + i - 1;
    }
}