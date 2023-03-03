#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long number, mask;
    int shift, reverse;

    answer.reserve(numbers.size());
    for(int i = 0; i < numbers.size(); i++)
    {
        mask = 0x01;
        number = numbers[i];
        for(shift = 0; numbers[i] & mask; shift++)
        {
            mask = mask << 1;
        }
        
        number |= mask;
        for(reverse = shift; reverse > 0; reverse--)
        {
            mask = mask >> 1;
            if( numbers[i] & mask )
            {
                number &= ~mask;
                break;
            }
        }

        answer.push_back(number);
    }

    return answer;
}