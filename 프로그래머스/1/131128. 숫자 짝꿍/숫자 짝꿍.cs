using System;
using System.Text;

public class Solution 
{
    public string solution(string X, string Y) 
    {
        int[] countX = new int[10];
        int[] countY = new int[10];
        
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
        
        StringBuilder str = new StringBuilder();
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