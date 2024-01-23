#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int idx, idx2, tag, compare, compare2;
    int score = friends.size();

    string give, take;
    unordered_map<string, vector<int>> giftMap;
    unordered_map<string, int> friendsTag;
    vector<int> reserved(friends.size() + 1);

    for( idx = 0; idx < friends.size(); idx++ )
    {
        giftMap.insert(make_pair(friends[idx], reserved));
        friendsTag.insert(make_pair(friends[idx], idx));
    }

    for( idx = 0; idx < gifts.size(); idx++ )
    {
        give = gifts[idx].substr(0, gifts[idx].find(" "));
        take = gifts[idx].substr(gifts[idx].find(" ") + 1);
        tag = friendsTag[take];

        giftMap[give][tag]++;
        giftMap[give][score]++;
        giftMap[take][score]--;
    }

    for( idx = 0; idx < friends.size(); idx++ )
    {
        for( idx2 = idx + 1; idx2 < friends.size(); idx2++ )
        {
            compare = giftMap[friends[idx]][idx2] - giftMap[friends[idx2]][idx];
            compare2 = giftMap[friends[idx]][score] - giftMap[friends[idx2]][score];

            if( compare > 0 )
            {
                reserved[idx]++;
            }
            else if( compare < 0 )
            {
                reserved[idx2]++;
            }
            else
            {
                if( compare2 > 0 )
                {
                    reserved[idx]++;
                }
                else if( compare2 < 0 )
                {
                    reserved[idx2]++;
                }
            }
        }
        answer = (reserved[idx] > answer) ? reserved[idx] : answer;
    }

    return answer;
}