#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 두 단어가 변환 가능한지 확인 (한 글자만 다를 때 true)
bool canTransform(const string& word1, const string& word2) 
{
    int diffCount = 0;
    for (size_t i = 0; i < word1.size(); ++i) 
    {
        if (word1[i] != word2[i]) 
        {
            ++diffCount;
        }
        if (diffCount > 1)
        {
            return false; // 두 글자 이상 차이가 나면 false
        }
    }
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) 
{
    // target이 words에 없다면 변환 불가
    if (find(words.begin(), words.end(), target) == words.end()) 
    {
        return 0;
    }

    // BFS를 위한 큐와 방문 집합
    queue<pair<string, int>> q; // (현재 단어, 변환 단계 수)
    unordered_set<string> visited;

    // 초기 상태 삽입
    q.push({begin, 0});
    visited.insert(begin);

    while (!q.empty()) 
    {
        auto [currentWord, steps] = q.front();
        q.pop();

        // target에 도달하면 현재 단계 반환
        if (currentWord == target) 
        {
            return steps;
        }

        // words에서 변환 가능한 단어를 큐에 추가
        for (const auto& word : words) 
        {
            if (visited.find(word) == visited.end() && canTransform(currentWord, word)) {
                visited.insert(word);
                q.push({word, steps + 1});
            }
        }
    }

    return 0; // 변환 불가한 경우
}
