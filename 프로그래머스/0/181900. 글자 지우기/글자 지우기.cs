using System;

public class Solution 
{
    public string solution(string my_string, int[] indices) 
    {
        string answer = "";
        Array.Sort(indices);
        bool isBool = false;
        
        for (int i=0; i<my_string.Length; i++) {
            foreach(int indice in indices) {
                if(i == indice) {
                    isBool = true;
                }
            }
            
            if (!isBool) {
                answer += my_string[i];   
            }
            
            isBool = false;
        }
        return answer;
    }
}