#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define STD_SALE    0
#define STD_COST    1

#define MIN_DISCOUNT_TAG    1
#define MAX_DISCOUNT_TAG    4
#define MAX_EMOTICON_LIST   7
#define MAX_CASETABLE_IDX   5000000

int gDiscountMark[MAX_DISCOUNT_TAG + 1] = {0 };
int gDiscountPrice[MAX_EMOTICON_LIST][MAX_DISCOUNT_TAG + 1] = {0, };
int gCaseTable[MAX_CASETABLE_IDX] = {0, };

int GetTableIndex( int disList[], int maxIdx )
{
    int dIdx, ipow = 1;
    int tIdx = 0;

    for( dIdx = 0; dIdx < maxIdx; dIdx++ )
    {
        tIdx += disList[dIdx] * ipow;
        ipow *= 10;
    }

    return tIdx;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int index, discount, emo, tindex;
    int max_discount = MIN_DISCOUNT_TAG, min_discount = MAX_DISCOUNT_TAG;
    int discountList[MAX_EMOTICON_LIST] = {0, };
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
        max_discount = ( discount > max_discount ) ? discount : max_discount;
        min_discount = ( discount <= min_discount ) ? discount : min_discount;
    }
    min_discount += ( min_discount == 0 ) ? 1 : 0;

    cout << "max : " << max_discount << endl;
    cout << "min : " << min_discount << endl;

    memset(discountList, min_discount, sizeof(discountList));
    for( index = 0; index < users.size(); index++ )
    {
        memset(discountList, min_discount, sizeof(discountList));
        while( discountList[emoticons.size()-1] > max_discount )
        {
            cost = 0;
            for( emo = 0; emo < emoticons.size()-1; emo++ )
            {
                cost += gDiscountPrice[emo][discountList[emo]];
                if(discountList[emo] == max_discount)
                {
                    discountList[emo] = min_discount;
                    discountList[emo + 1]++;
                }
            }

            if( cost >= users[index][STD_COST] )
            {
                tindex = GetTableIndex(discountList, users.size());
                gCaseTable[tindex]++;
                cout << "casetable[" << tindex << "] = " << gCaseTable[tindex] << endl;
            }
            discountList[0]++;
        }
    }

    answer.push_back(emo);
    answer.push_back(cost);

    return answer;
}

int main()
{
    return 0;
}