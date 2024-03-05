#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(vector<vector<int>> &v1,  vector<vector<int>> &v2)
{
    return true;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> idxMap = { {"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3} };
    map<int, int> sortedMap;
    int extIdx, sortIdx;

    extIdx = idxMap[ext];
    sortIdx = idxMap[sort_by];

    for(int i = 0; i < data.size(); i++)
    {
        if( data[i][extIdx] >= val_ext )
            continue;

        sortedMap.insert({data[i][sortIdx], i});
    }

    for(auto iter = sortedMap.begin(); iter != sortedMap.end(); iter++)
    {
        answer.push_back(data[iter->second]);
    }

    return answer;
}