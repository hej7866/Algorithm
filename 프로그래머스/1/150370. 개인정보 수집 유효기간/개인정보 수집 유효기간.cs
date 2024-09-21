using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string today, string[] terms, string[] privacies) 
    {
        // 오늘 날짜를 배열로 바꾸는 과정 
        string[] t_str_arr = today.Split(".");
        int[] t_i_arr = new int[t_str_arr.Length];
        for(int i=0; i<t_str_arr.Length; i++)
        {
            t_i_arr[i] = Int32.Parse(t_str_arr[i]);
        }
        
        // terms를 Dictionary로 바꾸는 과정
        Dictionary<string, int> termsDic = new Dictionary<string, int>();
        
        for (int i = 0; i < terms.Length; i++)
        {
            string[] termParts = terms[i].Split(' '); // 각 요소를 분리
            if (termParts.Length == 2) // 분리된 부분이 두 개인지 확인
            {
                string key = termParts[0]; // 첫 번째 부분은 키
                termsDic[key] = Int32.Parse(termParts[1]);
            }
        }
        
        int num = 1;
        List<int> result = new List<int>();
        foreach(string p in privacies)
        {
            string[] pArr = p.Split(' '); // privacies를 공백을 기준으로 분리 [개인정보 수집 일자, 약관 종류]
            
            string t = pArr[1]; // 약관 종류 할당
            int a = termsDic[t]; // 약관 종류에 대응하는 유효기간
            
            string[] pvcArr = pArr[0].Split("."); // 개인정보 수집일자를 .을 기준으로 분리
            int[] pvc_i_Arr = new int[pvcArr.Length]; 
            for(int i=0; i<pvcArr.Length; i++)
            {
                pvc_i_Arr[i] = Int32.Parse(pvcArr[i]); // 분리한 날짜를 정수형으로 바꾸는 과정
            }
            
            
            // 기존 개인정보 수집 일자에 먼저 -1일을 해주는 과정 
            pvc_i_Arr[2] -= 1;
            if( pvc_i_Arr[2] == 0)
            {
                pvc_i_Arr[2] = 28;
                pvc_i_Arr[1] -= 1;
            }
            else if(pvc_i_Arr[1] == 0)
            {
                pvc_i_Arr[1] = 12;
                pvc_i_Arr[0] -= 1;
            }
            
            
            int tmp = pvc_i_Arr[1] + a;
            if(tmp > 12)
            {
                pvc_i_Arr[0] += tmp/12;
                pvc_i_Arr[1] = tmp%12;
                if(pvc_i_Arr[1] == 0)
                {
                    pvc_i_Arr[1] = 12;
                    pvc_i_Arr[0] -= 1;
                }
            }
            else if(tmp <= 12)
            {
                pvc_i_Arr[1] = tmp;
            }
            
            if(pvc_i_Arr[0] < t_i_arr[0])
            {
                result.Add(num);
                num++;
                continue;
            }
            else if(pvc_i_Arr[0] == t_i_arr[0] && pvc_i_Arr[1] < t_i_arr[1])
            {
                result.Add(num);
                num++;
                continue;
            }
            else if(pvc_i_Arr[0] == t_i_arr[0] && pvc_i_Arr[1] == t_i_arr[1] &&  pvc_i_Arr[2] < t_i_arr[2])
            {
                result.Add(num);
                num++;
                continue;
            }
            else
            {
                num++;
            }
            foreach(int i in pvc_i_Arr)
            {
                Console.WriteLine(i);
            }
            
        }        
        return result.ToArray();
    }
}