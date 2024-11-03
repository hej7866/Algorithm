using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[,] targets) 
    {
        // 2차원 배열을 List<int[]>로 변환하여 사용
        List<int[]> targetList = new List<int[]>();
        for (int i = 0; i < targets.GetLength(0); i++)
        {
            targetList.Add(new int[] { targets[i, 0], targets[i, 1] });
        }

        // 구간을 종료 지점 기준으로 정렬
        targetList.Sort((a, b) => a[1].CompareTo(b[1]));

        int missileCount = 0;
        double lastIntercept = -1.0;

        foreach (var target in targetList)
        {
            int start = target[0];
            int end = target[1];

            // 현재 요격 미사일로 커버할 수 없는 구간이 있으면 새로 발사
            if (lastIntercept < start)
            {
                lastIntercept = end - 0.5; // 개구간이므로 end 바로 직전에 요격 미사일을 발사
                missileCount++;
            }
        }

        return missileCount;
    }
}