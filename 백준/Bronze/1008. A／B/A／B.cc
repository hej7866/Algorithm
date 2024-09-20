#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
    long double a, b;
    cin >> a >> b;

    // 정확한 결과
    long double result = a / b;

    // 출력
    cout << fixed << setprecision(30) << result << endl;
    return 0;
}