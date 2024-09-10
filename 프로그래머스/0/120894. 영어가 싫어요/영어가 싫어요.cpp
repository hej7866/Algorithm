#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string numbers) 
{
    vector<string> numberStr = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<string> number = {"0","1","2","3","4","5","6","7","8","9"};
    long long answer = 0;
    
     for (int i = 0; i < numberStr.size(); i++) 
     {
        // 모든 위치 찾기
        size_t pos = numbers.find(numberStr[i]);
        while (pos != string::npos) 
        {
            numbers.replace(pos, numberStr[i].length(), number[i]);
            pos = numbers.find(numberStr[i], pos + 1); // 다음 위치를 찾기
        }
     }
    return stoll(numbers);
}