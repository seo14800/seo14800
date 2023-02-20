#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    int index, size;
    
    size = strlen(my_string);
    answer = (char*)malloc(size + 1);
    for(index = 0; index < size + 1; index++)
    {
        answer[index] = my_string[size-(index+1)];
        printf("%d : %c\n", index, answer[index]);
    }
    
    return answer;
}