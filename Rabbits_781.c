#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //INT_MIN

int numRabbits(int* answers, int answersSize){
    if (answersSize <= 1)
        return answersSize;

    int pint[1001];
    bzero(pint, 1001 * sizeof(int));

    int i = 0, sum = 0;
    int max = INT_MIN;
    for(i; i < answersSize; i++)
    {
        pint[answers[i]]++;
        if (answers[i] > max)
            max = answers[i];
    }

    for(i = 0; i <= max; i++)
    {
        if (pint[i])
        {
            int tmp1 = (i+1)*(pint[i]/(i+1));
            int tmp2 = (pint[i]%(i+1))?(i+1):0;
            int tmp = tmp1 + tmp2;
            sum += tmp; 
        }
    }

    return sum;
}

int main()
{
    int pint[7];
    int i = 0;
    for (; i<7; i++){
        pint[i] = 0;
    }
    int ret = numRabbits(pint, 7);
    printf("ret: %d\n", ret);
    return 0;
}