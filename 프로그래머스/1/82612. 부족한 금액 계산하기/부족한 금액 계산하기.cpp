using namespace std;

long long solution(int price, int money, int count)
{
    long long added = 0, cost = 0;
    long long answer = -1;

    for(int i = 0; i < count; i++ )
    {
        added += price;
        cost += added;
    }

    answer = cost - money;
    if( answer < 0 )
        return 0;

    return answer;
}