using System;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] array) 
    {
        int max = array.Max();
        int[] result = new int[2];
        result[0] = max;
        
        for(int i=0; i<array.Length; i++) {
            if(array[i] == max) {
                result[1] = i;
            }
        }
        
        return result;
    }
}