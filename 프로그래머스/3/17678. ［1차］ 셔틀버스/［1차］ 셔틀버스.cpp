#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int TimeConvert(const string &strTime)
{
    int hh = stoi(strTime.substr(0, strTime.find(':')));
    int mm = stoi(strTime.substr(strTime.find(':') + 1));
    return (hh * 60) + mm;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> crewArrival;

    for (const auto &time : timetable)
    {
        crewArrival.push_back(TimeConvert(time));
    }
    sort(crewArrival.begin(), crewArrival.end());

    vector<int> busDeparture(n);
    int busTime = 540;
    for (int i = 0; i < n; i++)
    {
        busDeparture[i] = busTime;
        busTime += t;
    }

    vector<int> onboard(n, 0);
    vector<int> lastBoarded(n, -1);

    int crewIdx = 0;
    for (int busIdx = 0; busIdx < n; busIdx++)
    {
        while (crewIdx < crewArrival.size() &&
               onboard[busIdx] < m &&
               crewArrival[crewIdx] <= busDeparture[busIdx])
        {
            lastBoarded[busIdx] = crewArrival[crewIdx];
            onboard[busIdx]++;
            crewIdx++;
        }
    }

    int candidateTime = 0;
    if (onboard[n - 1] < m)
    {
        candidateTime = busDeparture[n - 1];
    }
    else
    {
        candidateTime = lastBoarded[n - 1] - 1;
    }

    int hh = candidateTime / 60;
    int mm = candidateTime % 60;
    if (hh < 10)
    {
        answer += "0";
    }
    answer += to_string(hh) + ":";
    if (mm < 10)
    {
        answer += "0";
    }
    answer += to_string(mm);

    return answer;
}