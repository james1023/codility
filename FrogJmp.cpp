#include <stdio.h>

/*
int solution(int X, int Y, int D) {
 // write your code in C++11 (g++ 4.8.2)
 return (Y - X + (D - 1)) / D;    
}
*/

int solution(int X, int Y, int D)
{
    return X == Y ? 0 : ((Y - X) - 1) / D + 1;
}

int main(void)
{
    printf("%d\n", solution(10, 85, 30));
    printf("%d\n", solution(10, 40, 30));
    printf("%d\n", solution(10, 10, 30));
    return 0;
}
