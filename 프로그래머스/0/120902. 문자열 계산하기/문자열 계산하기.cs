using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string my_string) 
    {
        string[] operation = my_string.Split(' ');
        
        List<int> numList = new List<int>();
        List<string> operatorList = new List<string>();
        for(int i=0; i<operation.Length; i++) {
            if(i%2 == 0) {
                numList.Add(Int32.Parse(operation[i]));
            }
            else {
                operatorList.Add(operation[i].ToString());
            }
        }
        int result = numList[0];
        int idx = 0;
        while (idx < operatorList.Count) {
            switch(operatorList[idx]) {
                case "+":
                    result += numList[idx + 1];
                    break;
                case "-":
                    result -= numList[idx + 1];
                    break;   
            }
            idx++;
        }
        
        return result;
    }
}