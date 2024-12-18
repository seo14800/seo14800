#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int height = park.size();
    int width = park[0].size();

    sort(mats.begin(), mats.end());

    for(auto sqrSize : mats)
    {
        for(int i = 0; i <= height - sqrSize; i++)
        {
            for(int j = 0; j <= width - sqrSize; j++)
            {
                bool allNegative = true;
                // 현재 size x size 정사각형이 모두 -1인지 확인
                for (int x = i; x < i + sqrSize; ++x) 
                {
                    for (int y = j; y < j + sqrSize; ++y) 
                    {
                        if (park[x][y] != "-1")
                        {
                            allNegative = false;
                            break;
                        }
                    }

                    if (!allNegative)
                    {
                        break;
                    }
                }

                if(allNegative)
                {
                    answer = sqrSize;
                    break;
                }
            }
        }
    }

    return answer;
}