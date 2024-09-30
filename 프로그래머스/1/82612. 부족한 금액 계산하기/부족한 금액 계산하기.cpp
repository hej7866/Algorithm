using namespace std;

long long solution(int price, int money, int count)
{
    long long ans = 0;
    long long sum = 0;
    for(int i=1; i<=count; i++)
    {
        sum += price * i;
    }
    if(sum > money) { ans = sum - money; }
    else { ans = 0; }
    return ans;
}