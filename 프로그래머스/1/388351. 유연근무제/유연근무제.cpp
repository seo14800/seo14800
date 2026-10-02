#include <iostream>
#include <string>
#include <vector>

#define CALTIME(n)   ((n / 100) * 60) + (n % 100)

using namespace std;

enum {
    MON = 1, TUE, WEN, THR, FRI, SAT, SUN
};

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    for(int i = 0; i < timelogs.size(); i++)
    {
        int day = startday;
        int deadline = CALTIME(schedules[i]) + 10;
        for(int j = 0; j < timelogs[i].size(); j++)
        {
            if(day == SAT || day == SUN)
            {
                day = (day == SUN) ? MON : day + 1;
                continue;
            }
            if(deadline < CALTIME(timelogs[i][j]))
            {
                answer--;
                break;
            }
            day++;
        }
    }
    return answer;
}