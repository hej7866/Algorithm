#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int lastTime = attacks[attacks.size() - 1][0];
    
    bool isDie = false;
    int maxHp = health;
    int count = 0;
    int idx = 0;
    for(int i=0; i<=lastTime; i++)
    {
        if(i == attacks[idx][0])
        {
            health -= attacks[idx][1];
            if(health <= 0)
            {
                isDie = true;
                break;
            }
            count = 0;
            idx++;
        }
        else
        {
            if(maxHp == health)
            {
                continue;
            }
            else
            {
                if(count != bandage[0])
                {
                    health += bandage[1];
                    if(health > maxHp) health = maxHp;
                }
                else
                {
                    health += bandage[1];
                    health += bandage[2];
                    if(health > maxHp) health = maxHp;
                    count = 0;
                }
            }
        }
        count++;
        cout << health << " ";
    }
    
    if (!isDie)
    {
        if(health <= 0)
        {
            isDie = true;
        }
    }
    return !isDie ? health : -1; 
}