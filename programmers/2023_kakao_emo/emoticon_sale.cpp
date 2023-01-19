#include <string>
#include <vector>

using namespace std;

#define STD_SALE    0
#define STD_COST    1

#define MIN_DISCOUNT_TAG    1
#define MAX_DISCOUNT_TAG    4
#define MAX_EMOTICON_LIST   7

int gDiscountMark[MAX_DISCOUNT_TAG + 1] = {0 };
int gDiscountPrice[MAX_EMOTICON_LIST][MAX_DISCOUNT_TAG + 1] = {0, };

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int index, discount, emo;
    int cost = 0, emoplus = 0;

    for( index = 0; index < emoticons.size(); index++ )
    {
        for( discount = MIN_DISCOUNT_TAG; discount < MAX_DISCOUNT_TAG + 1; discount++ )
        {
            gDiscountPrice[index][discount] = emoticons[index] - ((emoticons[index] / 10) * discount);
        }
    }

    for( index = 0; index < users.size(); index++ )
    {
        discount = users[index][STD_SALE] / 10;
        for( emo = 0; emo < emoticons.size(); emo++ )
        {
            gDiscountPrice[index][discount] = emoticons[index] - ((emoticons[index] / 10) * discount);
            switch (discount)
            {
            case MIN_DISCOUNT_TAG - 1:  /* 0, there is no discount */
                break;
            
            default:
                break;
            }
        }
    }

    return answer;
}

int main()
{
    return 0;
}