using System;

class Solution
{
    public int solution(int n, int a, int b)
    {
        int count = 1;
        while(true)
        {
            if(a - b == 1 || b - a == 1)
            {
                if(a > b)
                {
                    if(a / 2 == b / 2 + 1)
                    {
                        break;
                    }
                }
                else
                {
                    if(a / 2 + 1 == b / 2)
                    {
                        break;
                    }
                }
            }
            
            
            if(a % 2 == 0)
            {
                a /= 2;
            }
            else
            {
                a /= 2;
                a += 1;
            }
            
            if(b % 2 == 0)
            {
                b /= 2;
            }
            else
            {
                b /= 2;
                b += 1;
            }
            count++;
        }
        return count;
    }
}