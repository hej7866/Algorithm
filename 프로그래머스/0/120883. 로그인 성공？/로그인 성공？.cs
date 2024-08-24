using System;

public class Solution 
{
    public string solution(string[] id_pw, string[,] db) 
    {
        bool idpw = false;
        string result = "";
        
        int row = db.GetLength(0);
        for(int r=0; r<row; r++) {
            if(id_pw[0] == db[r,0] && id_pw[1] == db[r,1]) {
                idpw = true;
                result = "login";
            }
        }
        
        bool id = false;
        bool pw = false;
        if(!idpw) {
            for(int r=0; r<row; r++) {
                if(id_pw[0] == db[r,0]) {
                    id = true;
                    result = "wrong pw";
                }
                else if(!id) {
                    pw = true;
                    result = "fail";
                }
            }
        }
        return result;
    }
}