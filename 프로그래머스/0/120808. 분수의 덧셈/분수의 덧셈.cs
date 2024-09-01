using System;

public class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) 
    {
        int[] fraction = new int[2];
        
        fraction[0] = numer1 * denom2 + numer2 * denom1;
        fraction[1] = denom1 * denom2;
        
        if(fraction[0] > fraction[1]) // 분자가 더 큰경우
        {
            int i = 2;
            while(i <= fraction[1])
            {
                if(fraction[0]%i == 0 && fraction[1]%i == 0)
                {
                    fraction[0] /= i;
                    fraction[1] /= i;
                    
                }
                else
                {
                    i++;
                }
            }
        }
        else if(fraction[0] < fraction[1]) // 분모가 더 큰 경우
        {
            int i = 2;
            while(i <= fraction[0])
            {
                if(fraction[0]%i == 0 && fraction[1]%i == 0)
                {
                    fraction[0] /= i;
                    fraction[1] /= i;
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            fraction[0] = 1;
            fraction[1] = 1;
        }
        return fraction;
    }
}