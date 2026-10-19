#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int prev = 0, curr = 1;

    for(int i = 2; i <= n; i++)
    {
        int next = (prev + curr) % 1234567;
        prev = curr;
        curr = next;
    }

    answer = curr;
    return answer;
}