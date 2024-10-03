using System;

public class Solution 
{
    public int solution(int[] a, int[] b) 
    {
        int n = a.Length;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += a[i] * b[i];
        }
        return ans;
    }
}