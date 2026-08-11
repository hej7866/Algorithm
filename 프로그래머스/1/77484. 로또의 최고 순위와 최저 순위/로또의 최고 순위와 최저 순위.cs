using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] lottos, int[] win_nums)
    {
        List<int> lottosList = new List<int>(lottos);
        foreach(int num in win_nums)
        {
            if(lottosList.Contains(num))
            {
                lottosList.Remove(num);
            }
        }

        int zeroCount = lottosList.Count(x => x == 0);
        int matchCount = 6 - lottosList.Count; // 지워진 개수 = 맞은 개수

        int[] result = new int[2];
        result[0] = GetRank(matchCount + zeroCount); // 최고 순위 (0들이 다 맞았다고 가정)
        result[1] = GetRank(matchCount);             // 최저 순위 (0들이 다 틀렸다고 가정)
        return result;
    }

    private int GetRank(int count)
    {
        switch(count)
        {
            case 6: return 1;
            case 5: return 2;
            case 4: return 3;
            case 3: return 4;
            case 2: return 5;
            default: return 6; // 0, 1개
        }
    }
}