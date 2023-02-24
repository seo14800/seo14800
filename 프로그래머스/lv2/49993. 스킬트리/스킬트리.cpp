#include <string>
#include <vector>

using namespace std;

#define MAX_SKILL_TYPE 26
#define CAL_SKILL_INDEX(x) x - 'A'

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    int convert;
    int priority;
    int skillmap[MAX_SKILL_TYPE] = { 0, };
    string cur_usr;

    for( priority = 0; priority < skill.size(); priority++ )
    {
        convert = CAL_SKILL_INDEX(skill[priority]);
        skillmap[convert] = priority + 1;
    }

    for( int cur = 0; cur < skill_trees.size(); cur++ )
    {
        cur_usr = skill_trees[cur];
        priority = 1;
        for( int ch = 0; ch < cur_usr.size(); ch++ )
        {
            convert = CAL_SKILL_INDEX(cur_usr[ch]);
            if( skillmap[convert] == 0 )
            {
                continue;
            }

            if( priority == skillmap[convert] )
            {
                priority++;
            }
            else
            {
                answer--;
                break;
            }
        }
    }

    return answer;
}