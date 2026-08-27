using System;

public class Solution 
{
    public long solution(int w, int h) 
    {      
        long answer = ((long)w * h) - (w + h - GCD(w,h));
        return answer;
    }
    
    int GCD(int w, int h)
    {
        if(h == 0)
        {
            return w;
        }
        
        return GCD(h, w % h); 
    }
}