#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);

    int shiftn = 0x01 << n - 1;
    for(int i = 0; i < n; i++)
    {
        int lapped = arr1[i] | arr2[i];
        for(int j = 0; j < n; j++)
        {
            int b = shiftn >> j;
            if(b & lapped)
            {
                answer[i] += '#';
            }
            else
            {
                answer[i] += ' ';
            }
        }
    }
    return answer;
}