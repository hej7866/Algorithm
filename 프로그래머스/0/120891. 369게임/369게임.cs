using System;

public class Solution 
{
    public int solution(int order) 
    {
        string orderStr = order.ToString();
        
        int count = 0;
        for(int i=0; i<orderStr.Length; i++) {
            switch(orderStr[i].ToString()) {
                case "3":
                case "6":
                case "9":
                    count++;
                    break;
                default:
                    break;     
            }
        }
        return count;
        
    }
}