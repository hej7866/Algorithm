using System;

public class Solution 
{
    public int solution(int[] numbers) 
    {
        int nl = numbers.Length;
        Array.Sort(numbers);
        
        int negativeCount = 0;
        for(int i=0; i<nl; i++)
        {
            if(numbers[i] < 0)
            {
                negativeCount++;
            }
        }
        
        int answer = 0;
        if(negativeCount < 2)
        {
            answer = (numbers[nl - 1] * numbers[nl - 2]);
        }
        else if(negativeCount >= 2)
        {
            if(numbers[nl - 1] * numbers[nl - 2] > (numbers[0] * numbers[1]))
            {
                answer = (numbers[nl - 1] * numbers[nl - 2]);
            }
            else
            {
                answer = (numbers[0] * numbers[1]);
            }
        }
        return answer;
    }
}