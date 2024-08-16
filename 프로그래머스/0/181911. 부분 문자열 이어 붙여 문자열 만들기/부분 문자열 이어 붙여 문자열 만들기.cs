using System;

public class Solution 
{
    public string solution(string[] my_strings, int[,] parts) 
    {
        string answer = "";
        string temp = "";
        
        string str = "";
        
        int r = 0;
        int start = 0;
        int end = 0;

         while (r<parts.GetLength(0)) {
            start = parts[r,0];
            end = parts[r,1];
            
            temp = my_strings[r];
             
            for (int idx=start; idx<=end; idx++) {
                str += temp[idx].ToString();
            }
            answer += str;
            str = "";   
            r++;
        }     
        return answer;
    }
}