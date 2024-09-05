using System;

public class Solution 
{
    public int[,] solution(int n) 
    {
        int[,] nArr = new int[n,n];
        
        int count = 1;
        
        int colMax = n - 1; // 오른쪽 경계
        int colMin = 0; // 왼쪽 경계
        int rowMax = n - 1; // 아래쪽 경계
        int rowMin = 0; // 위쪽 경계
        while(count <= n * n)
        {
            for(int j = colMin; j <= colMax; j++)
            {
                nArr[rowMin,j] = count;
                count++;
            }
            rowMin++;  // 위쪽 경계를 한칸 내림
            for(int i = rowMin; i <= rowMax; i++)
            {
                nArr[i,colMax] = count;
                count++;
            }
            colMax--; // 오른족 경계를 왼쪽으로 한칸 댕김
            for(int j = colMax; j>= colMin; j--)
            {
                nArr[rowMax,j] = count;
                count++;
            }
            rowMax--; // 아래쪽 경계를 위로 한칸 올림
            for(int i = rowMax; i >= rowMin; i--)
            {
                nArr[i,colMin] = count;
                count++;
            }
            colMin++; // 왼쪽 경계를 오른족으로 한칸 댕김      
        }
        return nArr;
    }
}