#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) 
{
    const int* A = (const int*)a;
    const int* B = (const int*)b;
    return(*B - *A);
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;

    qsort(B, B_len, sizeof(int), compare);
    qsort(A, A_len, sizeof(int), compare);

    int minA = A[A_len-1];
    int idxA = 0;
    for(int i = 0; i < B_len; i++)
    {
        if(B[i] < minA)
        {
            break;
        }
        for(int j = idxA; j < A_len; j++)
        {
            if(A[j] < B[i])
            {
                answer++;
                idxA = j + 1;
                break;
            }
        }
    }
    return answer;
}