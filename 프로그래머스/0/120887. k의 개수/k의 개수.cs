using System;
using System.Linq;
public class Solution 
{
    public int solution(int i, int j, int k) 
    {
        string strNum = "";
        int count = 0;
        for(int num=i; num<=j; num++) {
            strNum = num.ToString();
            for(int ln=0; ln<strNum.Length; ln++) {
                if(strNum[ln].ToString() == k.ToString()) {
                    count++;
                }    
            }
            strNum = "";
        }
        return count;
    }
}