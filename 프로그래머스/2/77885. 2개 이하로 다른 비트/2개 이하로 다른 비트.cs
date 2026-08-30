using System;
public class Solution 
{
    public long[] solution(long[] numbers) 
    {
        long[] result = new long[numbers.Length];
        for(int i = 0; i < numbers.Length; i++)
        {
            result[i] = NextNumber(numbers[i]);
        }
        return result;
    }
    
    long NextNumber(long x)
    {
        if((x & 1) == 0) // 짝수: 맨 끝자리가 0
        {
            return x + 1; // 그 자리만 1로 바꾸면 끝 (1비트 차이, 항상 최솟값)
        }
        
        // 홀수: 원래 공식 그대로 (c가 항상 1이라 정확히 맞음)
        long c = x & (-x);
        long r = x + c;
        long diff = x ^ r;
        long shifted = (diff >> 2) / c;
        return r | shifted;
    }
}