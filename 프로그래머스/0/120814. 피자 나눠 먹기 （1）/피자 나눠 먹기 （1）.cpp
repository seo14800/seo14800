#include <string>
#include <vector>

using namespace std;

#define PIECES  7

int solution(int n) {   
    if( n % PIECES )
    {
        return (n / PIECES) + 1;
    }
    
    return n / PIECES;
}