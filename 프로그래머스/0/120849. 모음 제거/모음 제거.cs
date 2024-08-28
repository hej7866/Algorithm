using System;

public class Solution 
{
    public string solution(string my_string) 
    {
        string[] vowel = {"a", "e", "i", "o", "u"};
        
        string result = "";
        for(int i=0; i<my_string.Length; i++)
        {
            bool isVowel = false;
            for(int j=0; j<vowel.Length; j++)
            {
                if(my_string[i].ToString() == vowel[j])
                {
                    isVowel = true;
                }
            }
            if(isVowel)
            {
                continue;
            }
            result += my_string[i].ToString();
        }
        return result;
    }
}