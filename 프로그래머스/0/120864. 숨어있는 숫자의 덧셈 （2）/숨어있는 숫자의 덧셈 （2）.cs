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
            } // 마지막 index에 숫자가 담긴다면 문자열에 붙지만 리스트에 추가는 안되므로 생각을 잘해야함!
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