using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int solution(string[] friends, string[] gifts) 
    {
        Dictionary<string, Dictionary<string,int>> dic = new Dictionary<string, Dictionary<string,int>>(); 
        Dictionary<string, int> giveDic = new Dictionary<string, int>();
        Dictionary<string, int> takeDic = new Dictionary<string, int>();
        // 딕셔너리 초기화 과정
        foreach(string friend in friends)
        {
            Dictionary<string, int> tmpDic = new Dictionary<string, int>();
            dic[friend] = tmpDic;
            giveDic[friend] = 0;
            takeDic[friend] = 0;
        }
        
        foreach(string gift in gifts)
        {
            string[] split = gift.Split(' ');
            string give = split[0];
            string take = split[1];
            
            if (!dic[give].ContainsKey(take))
            {
                dic[give][take] = 0;
            }
            dic[give][take]++;
    
            giveDic[give]++;
            takeDic[take]++;
        }
        
        Dictionary<string, int> giftVauleDic = new Dictionary<string, int>();
        foreach(string friend in friends)
        {
            giftVauleDic[friend] = giveDic[friend] - takeDic[friend];
        }
        
        int[] nextMonth = new int[friends.Length];  // 각 친구가 다음달에 받을 선물 수

        for (int i = 0; i < friends.Length; i++)
        {
            for (int j = i + 1; j < friends.Length; j++)  // i보다 뒤에 있는 것만 (중복 방지)
            {
                string a = friends[i];
                string b = friends[j];

                int aToB = dic[a].GetValueOrDefault(b, 0);  // a가 b에게 준 횟수
                int bToA = dic[b].GetValueOrDefault(a, 0);  // b가 a에게 준 횟수

                if (aToB > bToA)
                {
                    // a가 b에게 더 많이 줬으니, b가 a에게 하나 받음
                    nextMonth[i]++;
                }
                else if (aToB < bToA)
                {
                    nextMonth[j]++;
                }
                else
                {
                    // 주고받은 기록이 같거나 없으면 → 선물 지수 비교
                    if (giftVauleDic[a] > giftVauleDic[b])
                    {
                        nextMonth[i]++;
                    }
                    else if (giftVauleDic[a] < giftVauleDic[b])
                    {
                        nextMonth[j]++;
                    }
                    // 지수도 같으면 아무도 안 받음
                }
            }
        }

        return nextMonth.Max();
            
    }
}