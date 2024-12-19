#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int start = 0, end = 0;
    int curSum = 0;
    int minLen = sequence.size() + 1;
    vector<int> answer(2);

    while (end < n) 
    {
        curSum += sequence[end];

        while (curSum >= k) 
        {
            if (curSum == k && (end - start + 1) < minLen) 
            {
                minLen = end - start + 1;
                answer[0] = start;
                answer[1] = end;
            }
            curSum -= sequence[start];
            start++;
        }

        end++;
    }

    return answer;
}