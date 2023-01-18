#include <stdio.h>

int Cal_Black_Jack(int *Deck, int Size, int Max);

int main()
{
    int Card[100];
    int N, M;
    int i, BJ;

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &Card[i]);
    }

    BJ = Cal_Black_Jack(Card, N, M);

    printf("%d\n", BJ);

    return 0;
}

int Cal_Black_Jack(int *Deck, int Size, int Max)
{
    int result = 0, current = 0;
    int top, mid, bot;

    for(top = 0; top < Size - 2; top++)
    {
        for(mid = top + 1; mid < Size - 1; mid++)
        {
           for(bot = mid + 1; bot < Size; bot++)
            {
                current = Deck[top] + Deck[mid] + Deck[bot];
                if(current <= Max)
                {
                    if(result == 0)
                        result = current;
                    else if(current >= result)
                    result = current;
                }
            }
        }
    }

    return result;
}