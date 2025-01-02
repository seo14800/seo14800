#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> uKeymap;

    for(auto it : keymap)
    {
        for(int i = 0; i < it.size(); i++)
        {
            if(uKeymap.find(it[i]) != uKeymap.end())
            {
                int idx = i + 1;
                uKeymap[it[i]] = uKeymap[it[i]] > idx ? idx : uKeymap[it[i]];
            }
            else
            {
                uKeymap[it[i]] = i + 1;
            }
        }
    }

    for(auto target : targets)
    {
        int ans = 0;
        for(auto ch : target)
        {
            if(uKeymap.find(ch) == uKeymap.end())
            {
                ans = -1;
                break;
            }
            ans += uKeymap[ch];
        }
        answer.push_back(ans);
    }

    return answer;
}