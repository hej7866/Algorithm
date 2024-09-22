#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

 
/* 문제 

*/


/* 입력

*/


/* 출력

*/


/* 제한

*/


int main()
{
    int N;
    cin >> N;
    int t = N / 4;

    string str = "";
    for(int i=0; i<t; i++)
    {
        str += "long ";
    }
    str += "int";
    cout << str;
    return 0;
}

