#include <iostream>

using namespace std;

int solution(int storey) 
{
    int answer = 0;

    while (storey > 0) 
    {
        int digit = storey % 10;
        int next_digit = (storey / 10) % 10;

        if (digit < 5) 
        {
            answer += digit;
            storey /= 10;
            
        } 
        else if (digit > 5) 
        {
            answer += 10 - digit;
            storey = storey / 10 + 1;
        } 
        else 
        { // digit == 5
            if (next_digit >= 5) 
            {
                answer += 5;
                storey = storey / 10 + 1;
            } 
            else 
            {
                answer += 5;
                storey /= 10;
            }
        }
    }

    return answer;
}
