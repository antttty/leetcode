#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2)
        return numsSize;

    int low = 0, high = 1;

    int samecount = 1;
    for( ; high < numsSize; ){
        while (high < numsSize && nums[high] == nums[low]){
            samecount++;
            if (samecount == 2)
                nums[++low] = nums[high];
            high++;
        }
        if (high < numsSize)
        {
            nums[++low] = nums[high++]; 
            samecount = 1;
        }
    }
    return low+1;
}

int displaypint(int *pint, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d  ", pint[i]);
    }
    printf("\n");
}

int main()
{
    int *pint = malloc(12*sizeof(int));

    pint[0] = 0;
    pint[1] = 0;
    pint[2] = 1;
    pint[3] = 1;
    pint[4] = 1;
    pint[5] = 1;
    pint[6] = 2;
    pint[7] = 3;
    pint[8] = 3;
    int numsSize = 9;
    int ret = removeDuplicates(pint, numsSize);
    printf("ret : %d\n", ret);
    displaypint(pint, ret);
    free(pint);
    return 0;
}
