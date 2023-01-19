#include <stdio.h>

#define MAX 10000

int func_d(int n);

int main()
{
    int num[MAX] = {0, };
    int t_const;

    int i;
    for(i = 1; i <= MAX; i++)
    {
        t_const = func_d(i);
        if(t_const < MAX)
        {
            num[t_const] = 1;
        }
    }

    for(i = 1; i < MAX; i++)
    {
        if(!num[i])
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

int func_d(int n)
{
    int result = n;
    int p = 1;
    int filter;

    while(n / p)
    {
        p *= 10;
        filter = n % p;

        n -= filter;

        result += filter/(p/10);
    }

    return result;
}
