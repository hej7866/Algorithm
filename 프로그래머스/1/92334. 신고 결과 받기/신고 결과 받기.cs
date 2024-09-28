using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(string[] id_list, string[] report, int k) 
    {
        // 1단계: HashSet을 사용하여 고유한 보고서를 저장
        HashSet<string> uniqueReports = new HashSet<string>(report);
        
        // 2단계: 보고 수와 결과를 추적할 딕셔너리 생성
        Dictionary<string, int> reportCounts = new Dictionary<string, int>();
        Dictionary<string, int> result = new Dictionary<string, int>();

        // 결과 딕셔너리 초기화
        foreach (string id in id_list)
        {
            reportCounts[id] = 0; // 각 사용자의 보고 수
            result[id] = 0; // 각 사용자의 알림 수
        }

        // 3단계: 각 사용자에 대한 보고 수 카운트
        foreach (string r in uniqueReports)
        {
            string[] rep = r.Split(' ');
            string reporter = rep[0];
            string reported = rep[1];

            reportCounts[reported]++;
        }

        // 4단계: k 이상 보고된 사용자의 알림 수 카운트
        foreach (string r in uniqueReports)
        {
            string[] rep = r.Split(' ');
            string reporter = rep[0];
            string reported = rep[1];

            if (reportCounts[reported] >= k)
            {
                result[reporter]++;
            }
        }

        // 5단계: 최종 결과 배열 준비
        int[] ans = new int[id_list.Length];
        for (int i = 0; i < id_list.Length; i++)
        {
            ans[i] = result[id_list[i]];
        }

        return ans;
    }
}