public class Solution 
{
    public long solution(long n) 
    {
        long s = 1;
        while(s * s < n)
        {
            s++;
        }
    
        if(s * s == n)
        {
            return (s+1) * (s+1);
        }
        else
        {
            return -1;
        }
    }
}