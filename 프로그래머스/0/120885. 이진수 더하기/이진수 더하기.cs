using System;

public class Solution 
{
    public string solution(string bin1, string bin2) 
    {
        int bin1_int = 0;
        int bin2_int = 0;
        for(int i=0; i<bin1.Length; i++) {
            switch(bin1[i].ToString()) {
                case "1":
                    bin1_int += (int)Math.Pow(2,bin1.Length - i - 1); 
                    break;
                case "0":
                    break;
            }
        }
        for(int i=0; i<bin2.Length; i++) {
            switch(bin2[i].ToString()) {
                case "1":
                    bin2_int += (int)Math.Pow(2,bin2.Length - i - 1); 
                    break;
                case "0":
                    break;
            }
        }
        int bin_int = bin1_int + bin2_int;
        
        return Convert.ToString(bin_int, 2);;
    }
}