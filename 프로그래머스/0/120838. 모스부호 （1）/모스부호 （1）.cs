using System;

public class Solution
{
    public string solution(string letter) 
    {
        string[] morse = 
        { 
            ".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-",
            "-.--","--.."
        };
        string[] ch = 
        { 
            "a","b","c","d","e","f",
            "g","h","i","j","k","l",
            "m","n","o","p","q","r",
            "s","t","u","v","w","x",
            "y","z"
        };
        
        string[] letterList = letter.Split(' ');
        
        string result = "";
        for(int i=0; i<letterList.Length; i++)
        {
            for(int j=0; j<morse.Length; j++)
            {
                if(letterList[i] == morse[j])
                {
                    result += ch[j];
                }
            }
        }
        return result;
    }
}