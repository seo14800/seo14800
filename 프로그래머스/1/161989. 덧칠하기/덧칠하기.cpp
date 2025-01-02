#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = section.front();

    for(int sec : section)
    {
        if(start + m - 1 < sec)
        {
            answer++;
            start = sec;
        }
    }

    answer++;
    
    return answer;
}