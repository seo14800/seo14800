#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool matchId(const string& pattern, const string& candidate) 
{
    // 길이가 다르면 바로 false 반환
    if (pattern.size() != candidate.size()) 
    {
        return false;
    }

    if (all_of(pattern.begin(), pattern.end(), [](char ch) { return ch == '*'; })) 
    {
        return true;
    }
    
    // 각 문자 비교: 패턴 문자가 '*'이면 무시, 그렇지 않으면 두 문자가 같아야 함
    for (std::size_t i = 0; i < pattern.size(); i++) 
    {
        if (pattern[i] != '*' && pattern[i] != candidate[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int idx, const vector<string>& banned_id, const vector<string>& user_id, vector<bool>& used, unordered_set<string>& comb, unordered_set<string>& result)
{
    if (idx == banned_id.size())
    {
        // 선택된 user_id 집합은 순서에 관계없이 동일하면 같은 조합으로 취급합니다.
        // 이를 위해 comb에 저장된 아이디들을 정렬하여 하나의 문자열 키로 만듭니다.
        vector<string> tmp(comb.begin(), comb.end());
        sort(tmp.begin(), tmp.end());
        string key;
        for (const auto& s : tmp)
        {
            key += s + ",";
        }
        result.insert(key);
        return;
    }
    
    for (int i = 0; i < user_id.size(); i++)
    {
        if (!used[i] && matchId(banned_id[idx], user_id[i]))
        {
            used[i] = true;
            comb.insert(user_id[i]);
            dfs(idx + 1, banned_id, user_id, used, comb, result);
            comb.erase(user_id[i]);
            used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    vector<bool> used(user_id.size(), false);
    unordered_set<string> result;
    unordered_set<string> comb;
    
    dfs(0, banned_id, user_id, used, comb, result);
    
    answer = result.size();
    return answer;
}