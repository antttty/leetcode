#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


bool isUgly(int n){
    if (n == 1)
        return true;
    
    return ((n%2) == 0 && isUgly(n/2)) || 
            ((n%3) == 0 && isUgly(n/3)) || 
            ((n%5) == 0 && isUgly(n/5)) ;
}

int main()
{
    bool ret = isUgly(10);
    printf("ret:%d\n", ret);
    return 0;
}