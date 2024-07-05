#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> max_heap;
    int answer = 0;

    for (int e : enemy) {
        max_heap.push(e);
        if (n >= e) {
            n -= e;
        }
        else if (k > 0) {
            k--;
            if (!max_heap.empty()) {
                n += max_heap.top();
                max_heap.pop();
                n -= e;
            }
        }
        else {
            break;
        }
        answer++;
    }

    return answer;
}