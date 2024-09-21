#include <iostream>
#include <string>

using namespace std;


/*

*/
int main()
{
    int x, y;
    cin >> x >> y;

    int a;
    if(x > 0 && y > 0) { a = 1; }
    else if(x > 0 && y < 0) { a = 4; }
    else if(x < 0 && y > 0) { a = 2; }
    else if(x < 0 && y < 0) { a = 3; }

    cout << a;
    return 0;
}

