using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string polynomial) 
    {
        string[] plnmList = polynomial.Split(' ');
        
        List<string> varList = new List<string>(); // 변수(variable)를 담는 리스트 (ex)3x, x, 5x ....
        List<string> conList = new List<string>(); // 상수(Constant)를 담는 리스트 (ex)7, 5, 13 ...
        
        // 각 리스트에 값을 담아내는 과정 
        for(int i=0; i<plnmList.Length; i++)
        {
            if(i%2 == 0)
            {
                if(plnmList[i].Contains("x"))
                {
                    varList.Add(plnmList[i]);
                }
                else
                {
                    conList.Add(plnmList[i]);
                }
            }
        }
        
        string[] coefficientList = new string[varList.Count]; // 계수를 담을 배열 선언
        
        // 계수를 때서 리스트에 할당하는 과정
        for(int i=0; i<varList.Count; i++)
        {
            // varList[i]번째가 2글자이상이면 계수가 붙어있는 것 처음글자부터 마지막글자 전까지문자를 때서 붙인다. 
            if(varList[i].Length > 1)
            {
                string temp = varList[i];
                for(int j=0; j<varList[i].Length-1; j++)
                {
                    coefficientList[i] += temp[j].ToString();
                }
            }
            // 그렇지 않다면 계수가 1이므로 1을 할당
            else
            {
                coefficientList[i] = "1";
            }
        }
        
        int coefficient = 0; // 계수를 모두 더한 값을 담을 정수형 변수 선언
        for(int i=0; i<coefficientList.Length; i++)
        {
            coefficient += Int32.Parse(coefficientList[i]);
        }
        
        int Constant = 0; // 상수를 모두 더한 값을 담을 정수형 변수 선언
        for(int i=0; i<conList.Count; i++)
        {
            Constant += Int32.Parse(conList[i]);
        }
        
        string result = "";
        string variable = coefficient.ToString() + "x";
        string Const = Constant.ToString();
        if(coefficient > 0 && Constant > 0)
        {
            if(coefficient == 1) 
            {
                result = "x" + " " + "+" + " " + Const;
            }
            else
            {
                result = variable + " " + "+" + " " + Const;
            }
        }
        else if(coefficient > 0 && Constant == 0)
        {
            if(coefficient == 1) 
            {
                result = "x";
            }
            else
            {
                result = variable;
            }
        }
        else if(coefficient == 0 && Constant > 0)
        {
            result = Const;
        }
        
        return result;
    }
}