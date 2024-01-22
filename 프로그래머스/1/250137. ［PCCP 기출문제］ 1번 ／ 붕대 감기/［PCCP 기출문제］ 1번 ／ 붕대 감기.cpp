#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int PassedTime = 0;
    int PrevTime = 0;

    const int CastingTime = bandage[0];
    const int HealAmount = bandage[1];
    const int BonusHeal = bandage[2];
    const int MaxHP = health;
    int SuccessTime = 0;

    for(int AtkTime = 0; AtkTime < attacks.size(); AtkTime++)
    {
        PassedTime = attacks[AtkTime][0] - PrevTime;

        SuccessTime += PassedTime - 1;
        health += (bandage[1] * SuccessTime);

        while( (SuccessTime -= CastingTime) >= 0 )
        {
            health += BonusHeal;
        }

        health = (health > MaxHP) ? MaxHP : health; 

        health -= attacks[AtkTime][1];
        PrevTime = attacks[AtkTime][0];
        SuccessTime = 0;

        if( health <= 0 )
        {
            return -1;
        }
    }

    return health;
}