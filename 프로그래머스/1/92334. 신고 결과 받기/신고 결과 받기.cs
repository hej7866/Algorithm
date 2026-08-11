using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(string[] id_list, string[] report, int k) 
    {
        // key = 각 유저, value = 각 유저가 신고당한 횟수
        Dictionary<string, int> reportCountDic = new Dictionary<string, int>(); 
        
        // key = 각 유저, value = 각 유저가 신고한 id리스트
        Dictionary<string, List<string>> reportDic = new Dictionary<string, List<string>>();
        
        List<string> reportList = report.ToList();
        HashSet<string> reportHashSet = new HashSet<string>();
        
        foreach(string s in reportList)
        {
            reportHashSet.Add(s);
        }
        
        foreach(string id in id_list)
        {
            reportCountDic[id] = 0;
            reportDic[id] = new List<string>();
        }
        
        foreach(string r in reportHashSet)
        {
            string[] words = r.Split(' ');
            reportCountDic[words[1]]++; // words[1]이 신고당했으므로 카운트 추가;
            reportDic[words[0]].Add(words[1]);
        }
        
        int[] result = new int[id_list.Length];
        int idx = 0;
        foreach(var r in reportDic)
        {
            foreach(string s in r.Value)
            { 
                if(reportCountDic[s] >= k)
                {
                    result[idx]++;
                }
            }
            idx++;
        }
    
        return result;
        
    }
}