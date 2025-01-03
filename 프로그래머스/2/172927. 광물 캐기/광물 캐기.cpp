#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAX_MINING  (5)

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    enum { DIA = 0, IRON, STONE };
    enum { WEIGHT_STONE = 1, WEIGHT_IRON = 2, WEIGHT_DIA = 10 };
    unordered_map<string, int> mineMap = 
    {
        {"diamond", WEIGHT_DIA},
        {"iron", WEIGHT_IRON},
        {"stone", WEIGHT_STONE}
    };

    size_t pickSize = 0;
    for(auto pick : picks)
    {
        pickSize += pick * MAX_MINING;
    }
    if(pickSize < minerals.size())
    {
        minerals.resize(pickSize);
    }

    int weight = 0, mining = 0, start = 0;
    vector<pair<int, int>> sectionStress;
    for(auto mineral : minerals)
    {
        if(mining == MAX_MINING)
        {
            sectionStress.emplace_back(weight, start);
            start += mining;
            weight = 0;
            mining = 0;
        }
        weight += mineMap[mineral];
        mining++;
    }
    if(weight > 0)
    {
        sectionStress.emplace_back(weight, start);
    }

    sort(sectionStress.begin(), sectionStress.end(), greater<>());

    unordered_map<string, int> idxMap = 
    {
        {"diamond", DIA},
        {"iron", IRON},
        {"stone", STONE}
    };
    const int costMap[3][3] = 
    {   
        {1, 1, 1},
        {5, 1, 1},
        {25, 5, 1} 
    };
    for(auto section : sectionStress)
    {
        int curPick;
        if( picks[DIA] > 0)
        {
            curPick = DIA;
        }
        else if( picks[IRON] > 0 )
        {
            curPick = IRON;
        }
        else if( picks[STONE] > 0 )
        {
            curPick = STONE;
        }
        else
        {
            break;
        }

        picks[curPick]--;
        for(int i = section.second; (i < section.second + MAX_MINING && i < minerals.size()); i++)
        {
            answer += costMap[curPick][idxMap[minerals[i]]];
        }
    }

    return answer;
}