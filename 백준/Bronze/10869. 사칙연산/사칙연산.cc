#include <iostream>
// 두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a+b << "\n" << a-b << "\n" << a*b << "\n" << a/b << "\n" << a%b;
    return 0;
}
