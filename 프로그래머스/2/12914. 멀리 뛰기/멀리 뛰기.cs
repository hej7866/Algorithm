using System;

public class Solution 
{
    public long solution(int n) 
    {
        int MOD = 1234567;
        int[] arr = new int[2001];
        arr[0] = 1;
        arr[1] = 1;
        
        for(int i=2; i<=2000; i++)
        {
            arr[i] = (arr[i-1] + arr[i-2]) % MOD;
        }
        
        return arr[n];
    }
    
    
   
}