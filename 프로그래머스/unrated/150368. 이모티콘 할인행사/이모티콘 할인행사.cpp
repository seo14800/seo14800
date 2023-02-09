#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define STD_SALE    0
#define STD_COST    1
#define MAX_DISCOUNT_TAG    4
#define MAX_EMOTICON_LIST   7

int gDiscountPrice[MAX_EMOTICON_LIST][MAX_DISCOUNT_TAG] = {0, };
const int gDiscount[MAX_DISCOUNT_TAG] = { 10, 20, 30, 40 };
int gemoPlus = 0, gtotalSales = 0;

struct caseNode
{
    int depth;
    int service;
    int userpay;
    int totalpay;
    int discountlist[MAX_EMOTICON_LIST];
};

int solution_dfs(caseNode node, vector<vector<int>> users, vector<int> emoticons)
{
    if( node.depth == emoticons.size() )
    {
        for(int cur = 0; cur < users.size(); cur++)
        {
            node.userpay = 0;
            for(int emo = 0; emo < emoticons.size(); emo++)
            {
                if( gDiscount[node.discountlist[emo]] >= users[cur][STD_SALE] )
                {
                    node.userpay += gDiscountPrice[emo][node.discountlist[emo]];
                } 
            }

            if( node.userpay >= users[cur][STD_COST] )
            {
                node.service++;
            }
            else
            {
                node.totalpay += node.userpay;
            }
        }

        if( gemoPlus < node.service )
        {
            gemoPlus = node.service;
            gtotalSales = node.totalpay;
        }
        else if( gemoPlus == node.service && gtotalSales < node.totalpay )
        {
            gtotalSales = node.totalpay;
        }
    }
    else
    {
        node.depth++;
        for(int discount = 0; discount < MAX_DISCOUNT_TAG; discount++)
        {
            node.discountlist[node.depth] = discount;
            solution_dfs(node, users, emoticons);
        }
    }

    return 0;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    caseNode ansNode;
    int index, discount;

    for( index = 0; index < emoticons.size(); index++ )
    {
        for( discount = 0; discount < MAX_DISCOUNT_TAG; discount++ )
        {
            gDiscountPrice[index][discount] = (emoticons[index] / 100) * (100 - gDiscount[discount]);
        }
    }

    memset(&ansNode, 0, sizeof(ansNode));
    ansNode.depth = -1;
    solution_dfs(ansNode, users, emoticons);

    answer.push_back(gemoPlus);
    answer.push_back(gtotalSales);
    return answer;
}