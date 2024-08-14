using System;
using System.Collections.Generic;

public class Solution 
{    
    public int[] solution(int l, int r) 
    {
        string str = "";
        
        List<int> numbers = new List<int>();
        
        for (int i=l; i<=r; i++) {
            str = i.ToString();
            bool isValid = true;
            
            foreach (char ch in str) {
                if (ch != '5' && ch != '0') {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                numbers.Add(i);
            }
            
        }
        
        if (numbers.Count == 0) {
            numbers.Add(-1);
        }
        
        int[] answer = numbers.ToArray();  
        return answer;
    }
}