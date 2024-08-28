using System;

public class Solution 
{
    public int solution(int[] sides) 
    {
        Array.Sort(sides); // 일단 배열을 정렬한다.
        
        int count = 0;
        for(int i=1; i<=sides[1]; i++) // 가장 긴 변이 sides[1] 인경우
        {
            if(sides[1] < (sides[0] + i))
            {
                count++;
            }
        }
        
        for(int j=sides[1]+1; j<sides[1] + sides[0]; j++) // 가장 긴 변이 나머지 한 변 인경우
        { 
            count++;
        }
        return count;
    }
}