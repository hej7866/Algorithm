using System;
using System.Numerics;

public class Solution 
{
    public string solution(string a, string b) 
    {
        // 배열의 자릿수를 맞춰주기위한 도우미 변수
        int len = 0;  
        if(a.Length > b.Length)
        {
            len = a.Length;
        }
        else
        {
            len = b.Length;
        }
        // a와 b중 더 긴 길이로 배열의 길이를 설정한다.
        int[] aList = new int[len];
        int[] bList = new int[len];
        
        int[] answerList = new int[len + 1];
        
        // 만약 a가 "12533"이고 b가 "2453"면
        // aList = [1,2,5,3,3] bList = [0,2,4,5,3] 과 같이 담도록 짜준 코드
        int aidx = a.Length - 1;
        int bidx = b.Length - 1;
        for(int i=len-1; i>=0; i--)
        {
            if(aidx >= 0)
            {
                aList[i] = Int32.Parse(a[aidx].ToString());
            }
            else
            {
                aList[i] = 0;
            }
            
            if(bidx >= 0)
            {
                bList[i] = Int32.Parse(b[bidx].ToString());
            }
            else
            {
                bList[i] = 0;
            }
            aidx--;
            bidx--;       
        }
        
        // 덧셈 알고리즘 로직 
        // ex aList = [3,5,6] , bList = [3,8,2,7]  => answerList = [0,4,1,8,3]
        for(int i=len-1; i>=0; i--)
        {
            answerList[i+1] += aList[i] + bList[i];
            int temp = answerList[i+1];
            if(answerList[i+1] >= 10)
            {
                answerList[i+1] -= (temp / 10) * 10;
                answerList[i] += temp / 10;
            }
        }
        
        // answerList를 문자열로 바꾸는 로직
        string result = "";
        if(answerList[0] == 0)
        {
            for(int i=1; i<answerList.Length; i++)
            {
                result += answerList[i].ToString();
            }
        }
        else
        {
            for(int i=0; i<answerList.Length; i++)
            {
                result += answerList[i].ToString();
            }
        }
        return result;
    }
}