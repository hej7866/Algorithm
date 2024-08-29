using System;

public class Solution 
{
    public int[] solution(int[] numbers, string direction) 
    {
        int nl = numbers.Length;
        int lastTemp = numbers[nl-1];
        int firstTemp = numbers[0];
        switch(direction)
        {
            case "right":
                for(int i=0; i<nl-1; i++)
                {
                    numbers[nl-1-i] = numbers[nl-2-i];
                }
                numbers[0] = lastTemp;
                break;
            case "left":
                for(int i=1; i<nl; i++)
                {
                    numbers[i-1] = numbers[i];
                }
                numbers[nl-1] = firstTemp;  
                break;
        }
        return numbers;
    }
}