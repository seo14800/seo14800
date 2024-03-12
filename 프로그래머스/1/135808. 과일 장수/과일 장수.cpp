#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, appleNum = 0, box = 0;
    vector<int> scoreMap(k + 1, 0);

    for(int i = 0; i < score.size(); i++)
    {
        scoreMap[score[i]]++;
    }

    for(int i = k; i > 0; i--)
    {
        appleNum += scoreMap[i];
        if( appleNum >= m )
        {
            box = appleNum / m;
            appleNum -= box * m;
            answer += (m * i) * box;
        }
    }

    return answer;
}
