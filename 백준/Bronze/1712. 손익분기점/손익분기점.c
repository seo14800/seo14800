#include <stdio.h>

int main()
{
    int A, B, C, BEP = 0;
    int P;

    scanf("%d %d %d", &A, &B, &C);

    P = C - B;

    if(B >= C)
    {
        printf("-1");
        return 0;
    }

    BEP = (A / P) + 1;

    printf("%d\n", BEP);

    return 0;
}
