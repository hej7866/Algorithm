using System;

public class Solution 
{
    public int solution(string[] spell, string[] dic) 
    {
        int count = 0;
        bool isContains = false;
        for(int i=0; i<dic.Length; i++)
        {
            for(int j=0; j<spell.Length; j++)
            {
                if(dic[i].Contains(spell[j]))
                {
                    count++;
                }
            }
            if(count == spell.Length) {
                isContains = true;
                break;
            }
            count = 0;
        }
        return isContains ? 1 : 2;
    }
}