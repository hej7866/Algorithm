using System;

public class Solution 
{
    public string solution(string rsp) 
    {
        string rspCounter = "";
        for(int i=0; i<rsp.Length; i++) 
        {
            switch(rsp[i].ToString())
            {         
                case "2":
                    rspCounter += "0";
                    break;
                case "0":
                    rspCounter += "5";
                    break;
                case "5":
                    rspCounter += "2";
                    break;
            }
        }
        return rspCounter;
    }
}