#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

string convertBase(const int value, const int order)
{
    string strCovert;

    if(value == 0)
    {
        string zero("0");
        return zero;
    }

    int num = value;
    while(num > 0)
    {
        strCovert = char('0' + (num % order)) + strCovert;
        num /= order;
    }

    return strCovert;
}

int convertToDemical(const int value, const int order)
{
    int num = value;
    int conVal = 0;
    int digit = 1;
    while(num > 0)
    {
        conVal += (num % 10) * digit;
        num /= 10;
        digit *= order;
    }

    return conVal;
}

void findMinBase(const string& exp, int* order)
{
    if(order == nullptr)
        return;

    for(auto ch : exp)
    {
        if(ch >= '0' && ch <= '9')
        {
            int num = (ch - '0') + 1;
            *order = (num > *order) ? num : *order;
        }
    }
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> compExps, quesExps;

    int minOrder = 2;
    for(auto exp : expressions)
    {
        findMinBase(exp, &minOrder);
        if(exp.back() == 'X')
        {
            quesExps.push_back(exp);
        }
        else
        {
            compExps.push_back(exp);
        }
    }

    set<int> orderSet;
    for(int idx = minOrder; idx <= 9; idx++)
    {
        orderSet.insert(idx);
    }

    for(auto exp : compExps)
    {
        istringstream iss(exp);
        int a, b, ret;
        char oper, equal, x;

        iss >> a >> oper >> b >> equal >> ret;
        for(auto idx : orderSet)
        {
            int resultValue = convertToDemical(ret, idx);
            int demicalResult;
            switch (oper)
            {
            case '+':
                demicalResult = convertToDemical(a, idx) + convertToDemical(b, idx);
                break;

            case '-':
                demicalResult = convertToDemical(a, idx) - convertToDemical(b, idx);
                break;
            
            default:
                break;
            }

            if(resultValue != demicalResult)
            {
                orderSet.erase(idx);
            }
        }
    }

    for(auto ques : quesExps)
    {
        istringstream iss(ques);
        string prevStr, curStr;
        int a, b;
        char oper;

        iss >> a >> oper >> b;
        int prevResult = -1;
        int order = 2;
        for(auto idx : orderSet)
        {
            int demicalResult;
            switch (oper)
            {
            case '+':
                demicalResult = convertToDemical(a, idx) + convertToDemical(b, idx);
                break;

            case '-':
                demicalResult = convertToDemical(a, idx) - convertToDemical(b, idx);
                break;
            
            default:
                break;
            }

            if(prevResult == -1)
            {
                prevResult = demicalResult;
                prevStr = convertBase(prevResult, idx);
                order = idx;
            }

            curStr = convertBase(demicalResult, idx);
            if(prevStr != curStr)
            {
                prevResult = -1;
                break;
            }
        }

        if(prevResult == -1)
        {
            ques.back() = '?';
        }
        else
        {
            ques.pop_back();
            ques += convertBase(prevResult, order);
        }

        answer.push_back(ques);
    }

    return answer;
}