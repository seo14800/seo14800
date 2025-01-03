#include <string>
#include <vector>

using namespace std;

#define ALPHANUM    26

string solution(string s, string skip, int index) {
    string answer = "";
    int asciiArr[ALPHANUM];

    for(int i = 0; i < ALPHANUM; i++)
    {
        asciiArr[i] = 1;
    }

    int ascii;
    for(auto ch : skip)
    {
        ascii = ch - 'a';
        asciiArr[ascii] = 0;
    }

    for(auto ch : s)
    {
        ascii = ch - 'a';
        int idxSum = 0;
        while(idxSum < index)
        {
            ascii++;
            if(ascii >= ALPHANUM)
            {
                ascii = 0;
            }
            idxSum += asciiArr[ascii];
        }
        answer.push_back(ascii + 'a');
    }

    return answer;
}