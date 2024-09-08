#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) 
{
    int year1 = date1[0];
    int year2 = date2[0];
    
    int month1 = date1[1];
    int month2 = date2[1];
    
    int day1 = date1[2];
    int day2 = date2[2];
    
    if(year1 < year2)
    {
        return 1;
    }
    else if(year1 == year2)
    {
        if(month1 < month2)
        {
            return 1;
        }
        else if(month1 == month2)
        {
            if(day1 < day2)
            {
                return 1;
            } 
        }
    }
    return 0;
}