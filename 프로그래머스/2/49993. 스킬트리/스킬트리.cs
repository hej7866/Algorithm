using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string skill, string[] skill_trees) 
    {
        Dictionary<char, int> skillDic = new Dictionary<char, int>();
        
        for(int i=0; i<skill.Length; i++)
        {
            skillDic[skill[i]] = i;
            Console.WriteLine($"{skill[i]} , {i}");
        }
        
        int result = skill_trees.Length;
        foreach(string skill_tree in skill_trees)
        {
            int count = 0;  
            foreach(char c in skill_tree)
            {
                if(skillDic.ContainsKey(c))
                {
                    if(count != skillDic[c]) // 순서상 스킬트리랑 다르면
                    {
                        result--; // result올리고 브레이크
                        break;
                    }
                    else
                    { 
                        count++; // 순서상 스킬트리랑 같으면 다음 순서
                    }
                }
            }
        }
        return result;
    }
}