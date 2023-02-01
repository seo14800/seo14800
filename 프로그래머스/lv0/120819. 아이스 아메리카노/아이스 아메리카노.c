#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_MONEY       1000000
#define COST_AMERICANO  5500

int* solution(int money) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    if( money <= 0 && money > MAX_MONEY )
    {
        return -1;
    }
    
    int* answer = (int*)malloc(2);
    
    answer[0] = money / COST_AMERICANO;
    answer[1] = money % COST_AMERICANO;
    
    return answer;
}