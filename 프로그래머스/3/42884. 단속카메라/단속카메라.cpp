#include <string>
#include <vector>
#include <set>

using namespace std;

struct CompareBySecond
{
    bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
        return lhs[1] < rhs[1];
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    multiset<vector<int>, CompareBySecond> msRoutes;

    for(auto route : routes)
    {
        msRoutes.insert(route);
    }

    while(!msRoutes.empty())
    {
        int egress = (*msRoutes.begin())[1];
        bool eraseFlag = false;
        for(auto it = msRoutes.begin(); it != msRoutes.end();)
        {
            int ingress = (*it)[0];
            if(ingress <= egress)
            {
                it = msRoutes.erase(it);
                eraseFlag = true;
            }
            else
            {
                ++it;
            }
        }
        
        if(eraseFlag == true)
        {
            answer++;
        }
    }

    return answer;
}