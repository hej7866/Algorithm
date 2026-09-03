using System;

public class Solution
{
    public int[] solution(int n, long left, long right)
    {
        int[] result = new int[(int)(right - left + 1)]; // rigth - left + 1 길이만큼의 배열 선언

        for (long i = left; i <= right; i++)
        {
            // 2차원 배열을 1차원으로 나열했을때 이게 기존에 몇행 몇열에있는지 계산하는거
            long row = i / n; 
            long column = i % n;
            result[(int)(i - left)] = (int)Math.Max(row, column) + 1;
        }

        return result;
    }
}