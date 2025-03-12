#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(n > s) 
    {
        answer.push_back(-1);
        return answer;
    }

    int div = s / n;
    int mod = s % n;

    for(int i = 0; i < n; i++)
    {
        if(i < n - mod)
        {
            answer.push_back(div);
        }
        else
        {
            answer.push_back(div + 1);
        }
    }
    
    return answer;
}