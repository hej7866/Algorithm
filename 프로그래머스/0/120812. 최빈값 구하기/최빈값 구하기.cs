using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int solution(int[] array) 
    {
        int[] arrList = new int[1000];
        for(int i=0; i<array.Length; i++)
        {
            arrList[array[i]]++;
        }
        
        int max = arrList.Max();
        int count = 0;
        int mostCountValue = 0;
        for(int i=0; i<arrList.Length; i++)
        {
            if(arrList[i] == max)
            {
                count++;
                mostCountValue = i;
            }
        }
        

        int answer = (count > 1) ? -1 : mostCountValue;
        return answer;
    }
}