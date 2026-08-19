using System;
using System.Collections.Generic;

public class Solution 
{
    public int[,] solution(int n) 
    {
        List<int[]> list = new List<int[]>();
        Hanoi(n, list, 1, 2, 3);
        int[,] answer = new int[list.Count, 2];
        for (int i = 0; i < list.Count; i++)
        {
            answer[i, 0] = list[i][0];
            answer[i, 1] = list[i][1];
        }
        return answer;
    }
    
    static void Hanoi(int n, List<int[]> list, int a, int b, int c)
    {
        if (n == 0) return; // 종료 조건 (base case)

        Hanoi(n - 1, list, a, c, b);   // 1. N-1개를 보조 기둥으로
        int[] tmp = new int[] {a,c};
        list.Add(tmp);
        Hanoi(n - 1, list, b, a, c);   // 3. 보조 기둥의 N-1개를 목적지로
    }

}