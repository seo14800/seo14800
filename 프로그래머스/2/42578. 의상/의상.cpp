#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clMap;
    for (const auto& c : clothes)
        clMap[c[1]]++;

    int answer = 1;
    for (const auto& [type, cnt] : clMap)
        answer *= (cnt + 1);   // 해당 종류에서 하나 입기 or 안 입기

    return answer - 1;          // 모두 안 입는 경우 제외
}