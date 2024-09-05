#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) 
{
    for(int i=0; i<control.length(); i++)
    {
        switch(control[i])
        {             
            case 'w':
                n++;
                break;
            case 'a':
                n -= 10;
                break;
            case 's':
                n--;
                break;
            case 'd':
                n += 10;
                break; 
        }
    }
    return n;
}



// #include <string>
// #include <vector>
// #include <map>
// using namespace std;

// map <char, int> m = {{'w', 1}, {'s', -1}, {'d', 10}, {'a', -10}};
// int solution(int n, string control) 
// {
//     int answer = n;
//     for(char ch : control)
//         answer += m[ch];
//     return answer;
// }