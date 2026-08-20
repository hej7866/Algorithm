using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int n) 
    {
        List<int> placed = new List<int>();
        return Solve(0, n, placed);
    }
    
    int Solve(int row, int n, List<int> placed)
    {
        if (row == n) 
        {
            return 1; // 여기까지 왔으면 유효한 정답 하나 완성
        }
        
        int count = 0;
        for (int col = 0; col < n; col++)
        {
            if (IsSafe(row, col, placed))
            {
                placed.Add(col);
                count += Solve(row + 1, n, placed);
                placed.RemoveAt(placed.Count - 1); // 백트래킹: 마지막에 넣은 것 제거
            }
        }
        return count;
    }
    
    bool IsSafe(int row, int col, List<int> placed)
    {
        for (int prevRow = 0; prevRow < placed.Count; prevRow++)
        {
            int prevCol = placed[prevRow];
            
            // 같은 열
            if (prevCol == col) return false;
            
            // 대각선 (행 차이 == 열 차이면 대각선 위에 있는 것)
            if (Math.Abs(prevRow - row) == Math.Abs(prevCol - col)) return false;
        }
        return true;
    }
}