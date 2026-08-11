using System;

public class Solution 
{
    public int solution(int[] number) 
    {
        int count = 0;
        for (int i = 0; i < number.Length; i++)
        {
            for (int j = i + 1; j < number.Length; j++)      // j는 i보다 큰 인덱스부터
            {
                for (int k = j + 1; k < number.Length; k++)  // k는 j보다 큰 인덱스부터
                {
                    if(number[i] + number[j] + number[k] == 0)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}