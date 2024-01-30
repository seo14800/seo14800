#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &target1, vector<int> &target2)
{
    return target1[1] < target2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    vector<vector<int>>::iterator it;
    vector<int> range(2);

    sort(targets.begin(), targets.end(), compare);
    range = targets[0];
    for(auto target:targets)
    {
        if( target[1] < range[1] || target[0] >= range[1] )
        {
            range = target;
            answer++;
        }
    }

    return answer;
}