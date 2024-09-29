#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) 
{
    int answer = 0;

    int bill_min = (bill[0] > bill[1]) ? bill[1] : bill[0];
    int bill_max = (bill[0] > bill[1]) ? bill[0] : bill[1];
    int wallet_min = (wallet[0] > wallet[1]) ? wallet[1] : wallet[0];
    int wallet_max = (wallet[0] > wallet[1]) ? wallet[0] : wallet[1];
    
    while(bill_min > wallet_min || bill_max > wallet_max)
    {
        if(bill[0] > bill[1])
        {
            bill[0] /= 2;
        }
        else
        {
            bill[1] /= 2;
        }
        answer++;
        
        bill_min = (bill[0] > bill[1]) ? bill[1] : bill[0];
        bill_max = (bill[0] > bill[1]) ? bill[0] : bill[1];
        wallet_min = (wallet[0] > wallet[1]) ? wallet[1] : wallet[0];
        wallet_max = (wallet[0] > wallet[1]) ? wallet[0] : wallet[1];
    }
    return answer;
}