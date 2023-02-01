#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const int MAX_TERMS = 26;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    string term, privacy;
    string t_date[3];
    string p_date[4];
    istringstream sstoday(today);
    int valid_period[MAX_TERMS] = {0, };
    int vsize, cur, cut, idx, p_idx;
    int sub_year, sub_month, sub_day, cal_period;
    int day_period;
    
    idx = 0;
    cut = 0;
    p_idx = 0;
    while(idx < today.size())
    {
        if( today[idx] == '.')
        {
            t_date[p_idx] = today.substr(cut, idx - cut);
            p_idx++;
            cut = idx + 1;
        }
        idx++;
    }
    t_date[p_idx] = today.substr(cut);
    
    vsize = terms.size();
    for(cur = 0; cur < vsize; cur++)
    {
        term = terms[cur];
        valid_period[term[0] - 'A'] = stoi(term.substr(1));
    }
    
    vsize = privacies.size();
    for(cur = 0; cur < vsize; cur++)
    {
        privacy = privacies[cur];
        idx = 0;
        cut = 0;
        p_idx = 0;
        while(idx < privacy.size())
        {
            if( privacy[idx] == '.' )
            {
                p_date[p_idx] = privacy.substr(cut, idx - cut);
                p_idx++;
                cut = idx + 1;
            }
            else if( privacy[idx] == ' ')
            {
                p_date[p_idx] = privacy.substr(cut, 2);
                p_idx++;
            }
            idx++;   
        }
        day_period = 28 * valid_period[privacy[idx-1] - 'A'];
        
        sub_year = (stoi(t_date[0]) - stoi(p_date[0])) * 12 * 28;
        sub_month = (stoi(t_date[1]) - stoi(p_date[1])) * 28;
        sub_day = (stoi(t_date[2]) - stoi(p_date[2]));

        cal_period = sub_year + sub_month + sub_day;
        if( cal_period >= day_period )
        {
            answer.push_back(cur + 1);
        }
    }
    
    return answer;
}