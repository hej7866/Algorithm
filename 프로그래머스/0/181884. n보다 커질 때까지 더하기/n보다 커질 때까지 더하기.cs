using System;

public class Solution 
{
    public int solution(int[] numbers, int n) 
    {
        int sumNum = 0;
        for (int i=0; i<numbers.Length; i++) {
            sumNum += numbers[i];
            if(sumNum > n) {
                break;
            }
        }
        return sumNum;
    }
}