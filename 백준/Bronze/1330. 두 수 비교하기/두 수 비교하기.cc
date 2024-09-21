#include <iostream>
#include <string>

using namespace std;


/*
첫째 줄에 다음 세 가지 중 하나를 출력한다.
A가 B보다 큰 경우에는 '>'를 출력한다.
A가 B보다 작은 경우에는 '<'를 출력한다.
A와 B가 같은 경우에는 '=='를 출력한다.
*/
int main()
{
    int a,b;
    cin >> a >> b;

    string str;
    if(a > b)
    {
        str = ">";
    }
    else if(a < b)
    {
        str = "<";
    }
    else { str = "=="; }
    cout << str;
    return 0;
}

