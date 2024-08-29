using System;

public class Solution 
{
    public int[] solution(int[] numbers, int num1, int num2) 
    {
        int[] resultList = new int[num2-num1+1];
        
        int index = 0;
        for(int i=num1; i<=num2; i++)
        {
            resultList[index] = numbers[i];
            index++;
        }
        return resultList;
    }
}