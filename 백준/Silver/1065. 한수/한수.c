#include <stdio.h>

#define MAX 1000

int HanSum(int Num);

int main()
{
    int N;

    scanf("%d", &N);

    printf("%d\n", HanSum(N));

    return 0;
}

int HanSum(int Num)
{
    int i;
    int sum = 0;

    if(Num <= 99)
        return Num;

    int hs1, hs2, hs3;
    sum = 99;
    for(i = 100; i <= Num; i++)
    {
        hs1 = i / 100;
        hs2 = (i % 100) / 10;
        hs3 = (i % 100) % 10;

        if((hs1 - hs2) == (hs2 - hs3))
            sum++;
    }
    return sum;

}
