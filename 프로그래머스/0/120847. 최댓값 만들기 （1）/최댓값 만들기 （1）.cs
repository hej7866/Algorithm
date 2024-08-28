using System;

public class Solution 
{
    public int solution(int[] numbers) 
    {
        Array.Sort(numbers);
        
        return numbers[numbers.Length - 1] * numbers[numbers.Length - 2];
    }
}