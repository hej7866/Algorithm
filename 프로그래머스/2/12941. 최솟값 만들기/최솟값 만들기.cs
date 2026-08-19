using System;

public class Solution 
{
    public int solution(int[] A, int[] B) 
    {
        Array.Sort(A);
        Array.Sort(B);
        int min = 0;
        for(int i=0; i<A.Length; i++)
        {
            min += A[i] * B[A.Length - i - 1];
        }
        return min;
    }   
}