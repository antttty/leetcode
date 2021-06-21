#include <string.h>
#include <stdlib.h>
#include <iostream>

#define max(a,b) ((a)>(b)?(a):(b))

int minimumMountainRemovals(int* nums, int numsSize){
    int *element_left = (int *)malloc(numsSize * sizeof(int));
    int *element_right = (int *)malloc(numsSize * sizeof(int));

    int index = 0;
    element_left[0] = 0; element_right[numsSize-1] = 0;
    for (index = 1; index<numsSize; index++){
        int k = 0;
        element_left[index] = 0;
        element_right[numsSize-1-index] = 0;
        for (k = 0; k < index; k++){
            if (nums[index] > nums[k]){
                element_left[index] = max(element_left[index], element_left[k] + 1);
            }
            if (nums[numsSize- 1 - index] > nums[numsSize-1 - k]){
                element_right[numsSize-1-index] = max(element_right[numsSize-1-index],
                                                 element_right[numsSize - 1 - k] + 1);
            }
        }
    }

    int ret = 0;
    for (index = 1; index<numsSize; index++){
        ret = max(ret, element_left[index] + element_right[index]);
    }
    return numsSize - ret - 1;
}

int main(){
    int nums[] = {1,2,3};
    int ret =  minimumMountainRemovals(nums, sizeof(nums)/sizeof(int));
    std::cout <<"---------------ret:" << ret << '\n';
    return 0;
}