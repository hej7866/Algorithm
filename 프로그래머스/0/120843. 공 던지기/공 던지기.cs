using System;

public class Solution 
{
    public int solution(int[] numbers, int k) 
    {
        int count = 1;
        int index = 1;
        while(true)
        {
            count++;
            index += 2;
            if(index > numbers[numbers.Length-1])
            {
                switch(index - numbers[numbers.Length-1])
                {
                    case 1:
                        index = 1;
                        break;
                    case 2:
                        index = 2;
                        break;
                }
            }
            if(count == k)
            {
                break;
            }
        }
        return numbers[index-1];
    }
}