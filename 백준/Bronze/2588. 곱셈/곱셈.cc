#include <iostream>
#include <string>

using namespace std;


/*
* 
*/
int main()
{
    int a, b;
    cin >> a >> b;
    string str = to_string(b);
    cout << a * (str[2] - '0') << "\n" << a * (str[1] - '0') << "\n" << a * (str[0] - '0') << "\n" << a * b;
    return 0;
    
}

