#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cookie_len은 배열 cookie의 길이입니다.
int solution(int cookie[], size_t cookie_len) {
    int answer = 0;

    for(int i = 0; i < cookie_len-1; i++)
    {
        int left = i;
        int right = i+1;
        int left_sum = cookie[left];
        int right_sum = cookie[right];

        while(1)
        {
            if(left_sum == right_sum)
            {
                if(answer < left_sum)
                {
                    answer = left_sum;
                }
            }

            if(left_sum <= right_sum && left > 0)
            {
                left_sum += cookie[--left];
            }
            else if(left_sum > right_sum && right < cookie_len-1)
            {
                right_sum += cookie[++right];
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}