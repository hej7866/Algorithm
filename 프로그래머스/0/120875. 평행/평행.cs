using System;

public class Solution {
    public bool IsParallel(int x1, int y1, int x2, int y2)
    {
        return y1 * x2 == y2 * x1;
    }

    public int solution(int[,] dots) {
        bool parallel =
IsParallel(dots[0, 0] - dots[1, 0], dots[0, 1] - dots[1, 1], dots[2, 0] - dots[3, 0], dots[2, 1] - dots[3, 1]) 
||
IsParallel(dots[0, 0] - dots[2, 0], dots[0, 1] - dots[2, 1], dots[1, 0] - dots[3, 0], dots[1, 1] - dots[3, 1]) 
||
IsParallel(dots[0, 0] - dots[3, 0], dots[0, 1] - dots[3, 1], dots[1, 0] - dots[2, 0], dots[1, 1] - dots[2, 1]);

        return parallel ? 1 : 0;
    }
}
// using System;
// using System.Collections.Generic;
// using System.Linq;

// public class Solution 
// {
//     public int solution(int[,] dots) 
//     {
//         int row = dots.GetLength(0); // dots의 행의 갯수 (여기선 4개로 고정)
//         int[,] lines = new int[6,2]; // dots가 4개이므로 선은 6개가 생길것임.
        
//         int index = 0;
//         for(int r=0; r<row; r++) {
//             for(int j=r+1; j<row; j++) { // 종점 - 시점을 해주면 선이 하나 생성이 되는것을 이용하여 선 6개를 만들어줌
//                 lines[index,0] = dots[j,0] - dots[r,0]; 
//                 lines[index,1] = dots[j,1] - dots[r,1];
//                 index++;
//             }
//         }
//         List<float> slopeList = new List<float>();
//         for(int i=0; i<lines.GetLength(0); i++) {
//             int dx = lines[i,0];
//             int dy = lines[i,1];
//             slopeList.Add((float)dy/dx);
//         }
        
//        var duplicates = slopeList.GroupBy(n => n)         // 원소를 그룹화
//                                  .Where(g => g.Count() > 1) // 원소가 2번 이상 나타나는 그룹 필터링
//                                  .Select(g => g.Key)      // 중복된 원소 선택
//                                  .ToArray();
//                 for(int i=0; i<lines.GetLength(0); i++) {
//             int dx = lines[i,0];
//             int dy = lines[i,1];
            
//             bool isNegativeX = false;
//             bool isNegativeY = false;
//             if(dx < 0) {
//                 dx = -dx;
//                 isNegativeX = true;
//             }
//             else if(dy < 0) {
//                 dy = -dy;
//                 isNegativeY = true;
//             }
            
//             int j = 2;
//             while(j<=dx) {
//                 while(dx%j == 0 && dy%j == 0) {
//                     dx = dx/j;
//                     dy = dy/j;
//                 }
//                 j++;
//             }
//             lines[i,0] = (isNegativeX) ? -dx : dx;
//             lines[i,1] = (isNegativeY) ? -dy : dy;
//         }
        
//         int count = 0;
//         for(int i=0; i<lines.GetLength(0); i++) {
//             for(int j=i+1; j<lines.GetLength(0); j++) {
//                 if(lines[i,0] == lines[j,0] && lines[i,1] == lines[j,1]) {
//                     count++;
//                 }
//             }
//         }
        
//         return duplicates.Length > 0 ? 1 : 0;
//     }
// }
        