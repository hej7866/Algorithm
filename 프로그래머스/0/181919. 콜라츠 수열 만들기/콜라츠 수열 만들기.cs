using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int n) 
    {
        List<int> collatz = new List<int>();
        collatz.Add(n);
        while (collatz[collatz.Count-1] != 1) {

            if (collatz[collatz.Count-1]%2 == 0) {
                collatz.Add(collatz[collatz.Count-1]/2); 
            }
            else if (collatz[collatz.Count-1]%2 == 1) {
                 collatz.Add(3 * collatz[collatz.Count-1] + 1); 
            }
        }
        
        int[] answer = collatz.ToArray();  
        return answer; 
    }
}