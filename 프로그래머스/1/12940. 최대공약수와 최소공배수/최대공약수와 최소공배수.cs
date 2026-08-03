using System;
public class Solution 
{
    public int[] solution(int n, int m) 
    {
        int min = n > m ? m : n;
        int max = n > m ? n : m;
        int gcd = GCD(min, max);
        int lcm = (n * m) / gcd;

        return new int[] { gcd, lcm };

        int GCD(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    }
}