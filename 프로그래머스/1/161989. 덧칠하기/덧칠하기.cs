using System;

public class Solution 
{
    public int solution(int n, int m, int[] section) 
    {
        int count = 0;
        int currentEnd = 0; // 현재 커버하는 마지막 인덱스
        
        for (int i = 0; i < section.Length; i++)
        {
            // section[i]가 현재 커버 범위 안에 있는지 확인
            if (section[i] > currentEnd)
            {
                // 새로운 범위 시작
                count++;
                currentEnd = section[i] + m - 1; // 다음 커버할 범위 계산
            }
        }
        
        return count;
    }
}