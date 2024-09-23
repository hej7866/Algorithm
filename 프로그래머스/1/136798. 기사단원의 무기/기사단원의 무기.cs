using System;
using System.Collections.Generic;

public class Solution
{ 
    public int solution(int number, int limit, int power) 
    {
        int sum = 0;
        for (int i = 1; i <= number; i++)
        {
            int count = 0;

            // 약수 개수 계산
            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    count++; // j는 약수
                    if (j != i / j) // j와 i/j가 같지 않을 때
                    {
                        count++; // i/j도 약수
                    }
                }
            }
            if(count <= limit) { sum += count; }
            else if(count > limit) { sum += power; }
        }
        return sum;
    }
}