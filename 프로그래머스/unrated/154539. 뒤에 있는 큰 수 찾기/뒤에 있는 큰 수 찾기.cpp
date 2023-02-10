#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> checklist;
	
	for(int i = 0; i < numbers.size(); i++)
    {
        while((numbers[checklist.back()] < numbers[i]) && (checklist.empty() == false))
        {
            answer[checklist.back()] = numbers[i];
            checklist.pop_back();
        }
        checklist.push_back(i);
    }
    return answer;
}