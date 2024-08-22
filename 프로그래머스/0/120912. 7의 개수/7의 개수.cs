using System;

public class Solution 
{
    public int solution(int[] array) 
    {
        int count = 0;
        for(int i=0; i<array.Length; i++) {
            string str = array[i].ToString();
            for(int j=0; j<str.Length; j++) {
                if(str[j].ToString() == "7") {
                    count++;
                }
            }
        }
        return count;
    }
}