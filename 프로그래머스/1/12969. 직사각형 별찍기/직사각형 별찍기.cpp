#include <iostream>

using namespace std;

int main(void) 
{
    int a;
    int b;
    cin >> a >> b;
    string star = "";
    for(int i=0; i<a; i++)
    {
        star += "*";
    }
    
    for(int i=0; i<b; i++)
    {
        cout << star << "\n";
    }
    return 0;
}