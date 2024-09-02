using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] rank, bool[] attendance) 
    {
        int ranking = 1; 
        int count = 0; // 1 2 3 등 3명을 걸러내기 위한 도구형 변수
        
        List<int> fstRank = new List<int>(); // first second third 1,2,3등의 인덱스를 추가하기위한 리스트
        while(fstRank.Count != 3) 
        { 
            int index = 0;
            for(int i=0; i<rank.Length; i++) // rank배열을 순회하면서
            {
                if(rank[i] == ranking) // rank의 i번째인덱스 값과 ranking값이 같다면
                {
                    index = i; // index에 i를 할당
                }
            }
            if(attendance[index]) // 그 인덱스 자리의 bool값이 트루라면 참가 하는것
            {
                fstRank.Add(index); // 그 값을 리스트에 추가하고
                count++; // count를 1증가
            }
            ranking++; // 마지막에 ranking 값 1 증가
        }
        
        return 10000 * fstRank[0] + 100 * fstRank[1] + fstRank[2];
    }
}