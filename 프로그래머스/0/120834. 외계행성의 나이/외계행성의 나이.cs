using System;

public class Solution {
    public string solution(int age) {
        string[] ageStrList = {"a","b","c","d","e","f","g","h","i","j"};
        
        string ageStr = age.ToString();
        string result = "";
        for(int i=0; i<ageStr.Length; i++)
        {
            result += ageStrList[Int32.Parse(ageStr[i].ToString())];
        }
        return result;
    }
}