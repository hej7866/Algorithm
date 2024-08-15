using System;

public class Solution 
{
    public string solution(string my_string, int[,] queries) 
    {
        string answer = "";
        char[] temp = my_string.ToCharArray();
        
        for(int r=0; r<queries.GetLength(0); r++) {
            int start = queries[r, 0];
            int end = queries[r, 1];
            
            Array.Reverse(temp, start, end - start + 1);
         }
        answer = new string(temp);
        return answer;
    }
}