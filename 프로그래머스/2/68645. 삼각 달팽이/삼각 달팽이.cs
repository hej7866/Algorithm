using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int n) 
    {
        int[][] triangle = new int[n][];
        for(int i = 0; i < n; i++)
        {
            triangle[i] = new int[i + 1]; // i번째 행은 칸이 i+1개
        }

        int[] dRow = {1, 0, -1};  // 아래, 오른쪽, 대각선(왼쪽위)
        int[] dCol = {0, 1, -1};
        int dir = 0;

        int row = 0, col = 0;
        int num = 1;
        int total = n * (n + 1) / 2;
        triangle[0][0] = num++;

        while(num <= total)
        {
            int nr = row + dRow[dir];
            int nc = col + dCol[dir];

            // 범위 밖이거나 이미 채워진 칸이면 방향 전환
            if(nr < 0 || nr >= n || nc < 0 || nc > nr || triangle[nr][nc] != 0)
            {
                dir = (dir + 1) % 3;
                nr = row + dRow[dir];
                nc = col + dCol[dir];
            }

            row = nr;
            col = nc;
            triangle[row][col] = num++;
        }

        List<int> answer = new List<int>();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                answer.Add(triangle[i][j]);
            }           
        }

        return answer.ToArray();
    }
}