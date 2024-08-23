using System;
using System.Collections.Generic;

public class Solution
{
    public long solution(string numbers)
    {
        string[] zero_to_nine = new string[] 
        {"zero","one","two","three","four","five","six","seven","eight","nine"};
        
        string[] int_zero_to_nine = new string[] 
        {"0","1","2","3","4","5","6","7","8","9"};
        
        for(int i=0; i<zero_to_nine.Length; i++){
            if(numbers.Contains(zero_to_nine[i]))
            numbers = numbers.Replace(zero_to_nine[i],int_zero_to_nine[i]);   
        }
        long answer = long.Parse(numbers);
        return answer;
    }
}

