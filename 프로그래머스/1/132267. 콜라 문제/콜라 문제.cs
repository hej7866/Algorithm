using System;

public class Solution 
{
    public int solution(int a, int b, int n) 
    {
        int sum = 0;
        int m = 0;
        while(n>=a)
        {
            m = (n/a)*b;
            n = n - ((n/a)*a) + (n/a)*b;
            sum += m;
            Console.WriteLine(m);
        }
        return sum;   
    }
}