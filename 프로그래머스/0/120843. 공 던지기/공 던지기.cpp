#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) 
{
    int index = 0;
    int count = 1;
    while(count != k)
    {
        index += 2;
        if(index > numbers.size()-1)
        {
            index = index - numbers.size();
        }
        count++;
    }
    return numbers[index];
}