#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    map<string, int> spoiler_words;
    map<string, int> non_spoiler_words;

    int spoiler_index = 0;
    for(int i = 0; i < message.size(); i++)
    {
        int start = i;
        if(message[i] == ' ')
        {
            continue;
        }

        while(i < message.size() && message[i] != ' ')
        {
            i++;
        }

        int end = i - 1;
        string word = message.substr(start, end - start + 1);

        while(spoiler_ranges[spoiler_index][1] < start && spoiler_index < spoiler_ranges.size() - 1)
        {
            spoiler_index++;
        }

        if(start <= spoiler_ranges[spoiler_index][1] && end >= spoiler_ranges[spoiler_index][0])
        {
            if(spoiler_words.find(word) == spoiler_words.end())
            {
                spoiler_words[word] = 1;
                if(non_spoiler_words.find(word) != non_spoiler_words.end())
                {
                    spoiler_words[word]++;
                }
            }
        }
        else
        {
            if(spoiler_words.find(word) != spoiler_words.end())
            {
                spoiler_words[word]++;
            }
            else
            {
                non_spoiler_words[word] = 1;
            }
        }
    }

    for(const auto& word : spoiler_words)
    {
        if(word.second == 1)
        {
            answer++;
        }
    }
    return answer;
}