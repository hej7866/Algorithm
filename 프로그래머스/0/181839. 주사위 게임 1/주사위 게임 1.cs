using System;

public class Solution 
{
    public int solution(int a, int b) 
    {
        int oddCount = 0;
        if(a%2 == 1)
        {
            oddCount++;
        }
        if(b%2 == 1)
        {
            oddCount++;
        }
        
        int answer = 0;
        if(oddCount == 2)
        {
            answer = a * a + b * b;
        }
        else if(oddCount == 1)
        {
            answer = 2 * (a + b);
        }
        else
        {
            answer = Math.Abs(a-b);
        }
        
        return answer;
    }
}