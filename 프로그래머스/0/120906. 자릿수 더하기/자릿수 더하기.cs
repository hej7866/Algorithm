using System;

public class Solution {
    public int solution(int n) 
    {
        string numStr = n.ToString();
        int numSum = 0;
        for(int i=0; i<numStr.Length; i++) {
            numSum += Int32.Parse(numStr[i].ToString());
        }
        return numSum;
    }
}