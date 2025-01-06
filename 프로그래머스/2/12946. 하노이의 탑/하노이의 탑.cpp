#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int aux, vector<vector<int>>& answer) {
    if (n == 1) 
    {
        // 원판 1개를 목적지로 이동
        answer.push_back({from, to});
        return;
    }
    // n-1개의 원판을 보조 기둥으로 이동
    hanoi(n - 1, from, aux, to, answer);
    // 가장 큰 원판을 목적지로 이동
    answer.push_back({from, to});
    // n-1개의 원판을 보조 기둥에서 목적지로 이동
    hanoi(n - 1, aux, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}