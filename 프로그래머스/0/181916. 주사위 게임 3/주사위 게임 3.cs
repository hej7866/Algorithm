using System;

public class Solution 
{
    public int solution(int a, int b, int c, int d) 
    {
        int[] diceRolls = new int[] { a, b, c, d};
        int[] counts = new int[6];
        int answer = 0;
        
        foreach (int roll in diceRolls) {
            counts[roll - 1]++;
        }
        
        int CheckThree = -1;
        int CheckTwo = -1;
        int CheckOne = -1;
        
        int CheckTwoCount = 0;
        int TwoSave1 = 0;
        int TwoSave2 = 0;
        
        int CheckOneCount = 0;
        int OneSave1 = 0;
        int OneSave2 = 0;
        int OneSave3 = 0;
        int OneSave4 = 0;
        
        
        for (int i=0; i<6; i++) {
            if(counts[i] == 4) {
                answer = (i+1) * 1111;
            }
            else if (counts[i] == 3) {
                CheckThree = i + 1;
            }
            else if (counts[i] == 2) {
                CheckTwo = i + 1;
                CheckTwoCount++;
                if (CheckTwoCount == 1) {
                    TwoSave1 = CheckTwo;
                }
                else if (CheckTwoCount == 2) {
                    TwoSave2 = CheckTwo;
                }
            }
            else if (counts[i] == 1) {
                CheckOne = i + 1;
                CheckOneCount++;
                if (CheckOneCount == 1) {
                    OneSave1 = CheckOne;
                }
                else if (CheckOneCount == 2) {
                    OneSave2 = CheckOne;
                }
                else if (CheckOneCount == 3) {
                    OneSave3 = CheckOne;
                }
                else if (CheckOneCount == 4) {
                    OneSave4 = CheckOne;
                }
            }
        }
        
        if (CheckThree != -1 && CheckOne != -1) {
            answer = (10 * CheckThree + CheckOne) * (10 * CheckThree + CheckOne);
        }
        
        if (CheckTwoCount == 1 && CheckOneCount == 2) {
            answer = OneSave1 * OneSave2;
        }
        
        if (CheckTwoCount == 2) {
            answer = (TwoSave1 + TwoSave2) * Math.Abs(TwoSave1 - TwoSave2);
        }
        
        if (CheckOneCount == 4) {
            answer = Math.Min(Math.Min(OneSave1, OneSave2), Math.Min(OneSave3, OneSave4));;
        }
        

        return answer;
    }
}
