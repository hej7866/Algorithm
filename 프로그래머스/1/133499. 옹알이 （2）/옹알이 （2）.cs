using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string[] babbling) 
    {
        Dictionary<string, string> dic = new Dictionary<string, string>();
        
        string[] Key = new string[] {"aya", "ye", "woo", "ma"};
        string[] Value = new string[] {"@", "#", "$", "%"};
        
        int answer = 0;
        for(int i=0; i<Key.Length; i++)
        {
            dic[Key[i]] = Value[i];
        }
        
        for(int i=0; i<babbling.Length; i++)
        {
            for(int j=0; j<Key.Length; j++)
            {
                while(babbling[i].Contains(Key[j]))
                {
                    babbling[i] = babbling[i].Replace(Key[j],dic[Key[j]]);
                }
            }
        }
        
        foreach(string str in babbling)
        {
            bool isBool = false;
            for(int i=0; i<str.Length; i++)
            {
                if(str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%')
                {
                    isBool = true;
                }
                else
                {
                    isBool = false;
                    break;
                }
            }
            
            bool isSame = false;
            if(isBool)
            {
                for(int i=0; i<str.Length - 1; i++)
                {
                    if(str[i] == str[i+1])
                    {
                        isSame = true;
                        break;
                    }
                }
            }
            if(isBool && !isSame)
            {
                answer++;
            }
            Console.WriteLine(answer);
        }
        return answer;
    }
}