#include <iostream>
#include <string>

using namespace std;


/*
* 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.
*/
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A+B)%C << "\n" << ((A%C) + (B%C))%C << "\n" << (A*B)%C << "\n" << ((A%C) * (B%C))%C;
    return 0;
}

