#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int jump(int* nums, int numsSize){
    unsigned int rets[1000] ;//only rets[0]=__INT_MAX__2147483647
    memset(rets, __INT_MAX__, 1000*sizeof(unsigned int));
    rets[0] = 0;
    int i = 0;
    for(; i < numsSize; i++){
        int r = i + nums[i];
        int j = i + 1;
        for(; j < numsSize && j <= r; j++){
            if (rets[j] > rets[i] + 1)
                rets[j] = rets[i] + 1;
        }   
    }
    return rets[numsSize - 1];
}

int main(){
    int     nums[5] = {2,3,1,1,4};
    printf("%d\n", jump(nums, 5));
    return 0;
}