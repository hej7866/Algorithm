using System;
using System.Text;

public class Solution 
{
    public string solution(string X, string Y) 
    {
        int[] countX = new int[10]; // X에 포함된 숫자의 카운트를 담을 배열
        int[] countY = new int[10]; // Y에 포함된 카운트를 담을 배열
        
        // 각 숫자 카운트 세는 작업
        foreach (char c in X)
        {
            countX[c - '0']++;
        }
        
        foreach (char c in Y)
        {
            countY[c - '0']++;
        }
        
        int[] numArr = new int[10];
        for(int i=0; i<=9; i++)
        {
            numArr[i] = Math.Min(countX[i], countY[i]);
        }
        
        StringBuilder str = new StringBuilder(); // 이 문제의 핵심(시간 복잡도 해결)
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < numArr[i]; j++)
            {
                str.Append(i); // StringBuilder에 숫자 추가
            }
        }
        string result = str.ToString();
        
        
        bool isOverOne = false;
        for(int i=1; i<=9; i++)
        {
            if(numArr[i] > 0) { isOverOne = true; }
        }
        if(!isOverOne)
        {
            if(numArr[0] != 0)
            {
                result = "0";
            }
            else if(numArr[0] == 0)
            {
                result = "-1";
            }
        }
        return result;
    }
}