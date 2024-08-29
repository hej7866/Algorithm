using System;

public class Solution 
{
    public double solution(int balls, int share) 
    {
        
        double n = 1;
        double m = 1;
        double r = 1;
        
        
        for(double i=1; i<=balls; i++)
        {
            n *= i;
        }
        for(double j=1; j<=share; j++)
        {
            m *= j;
        }
        if(balls > share)
        {
            for(double k=1; k<=(balls - share); k++)
            {
                r *= k;
            }     
        }
        else if(balls == share)
        {
            r = 1;
        }
        
        double combination =  Math.Round(n / (m * r));
        return combination;
    }
}