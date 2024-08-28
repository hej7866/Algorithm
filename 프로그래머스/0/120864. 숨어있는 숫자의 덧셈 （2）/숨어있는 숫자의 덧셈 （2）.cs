using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string my_string) 
    {
        string numStr = "";
        List<string> numList = new List<string>();
        bool isInt = false;
        for (int i = 0; i < my_string.Length; i++)
        {
            // 현재 문자가 숫자인 경우
            if (Char.IsDigit(my_string[i]))
            {
                numStr += my_string[i];
            }
            else
            {
                // 현재 문자가 숫자가 아니고, numStr에 숫자가 담겨있다면
                if (numStr.Length != 0)
                {
                    numList.Add(numStr);
                    numStr = ""; // numStr 초기화
                }
            }
        }

        // 문자열의 마지막 부분에 숫자가 남아 있을 수 있음
        if (numStr.Length != 0)
        {
            numList.Add(numStr);
        }
        
        int numSum = 0;
        for(int i=0; i<numList.Count; i++)
        {
            numSum += Int32.Parse(numList[i]);
        }
        return numSum;
    }
}