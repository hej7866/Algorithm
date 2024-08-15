using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string[] intStrs, int k, int s, int l) 
    {
        string strSub = "";
        List<int> numbers = new List<int>();
        for (int i=0; i<intStrs.Length; i++) {
            string str = intStrs[i];
            for(int j=s; j<s+l; j++) {
                strSub += str[j].ToString();
            }
            int num = Int32.Parse(strSub);
            if (num > k) {
                numbers.Add(num);   
            }
            strSub = "";
        }
        int[] answer = numbers.ToArray();
        return answer;
    }
}