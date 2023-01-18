#include <stdio.h>

int main()
{
    int N;
    int Total = 0;

    scanf("%d", &N);

    while(1)
    {
        if(N % 5 == 0)
        {
            Total += N / 5;
            break;
        }

        N -= 3;
        Total++;

        if(N < 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", Total);
    return 0;
}
