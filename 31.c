#include <stdbool.h>

void nextPermutation(int* nums, int numsSize){
    int     i = 0;
    int     index = 0;
    bool    ismax = false;
    int     tmp = 0;
    for(i=numsSize-2; i>=0; i--){
        if (nums[i] < nums[i+1]){//从后向前遍历 找到第一个非升序的数
            tmp = nums[i];
            for( index=numsSize-1; index>i ; index--){
                if (nums[index] > nums[i]){
                     nums[i] = nums[index];
                    nums[index] = tmp;
                    break;
                }   
            }
            index = i+1;
            for (int j = numsSize-1; index<=j;){//i +1至 numsSize -1 逆序
                tmp = nums[index];
                nums[index++] = nums[j];
                nums[j--] = tmp;
            }
            break;
        }else if (i == 0){
            ismax = true;
            break;
        }
    }

    tmp = 0;
    if (ismax){ //已是最大的排列
        int j = numsSize - 1;
        for (i = 0; i <j ;){
            tmp = nums[j];
            nums[j--] = nums[i];
            nums[i++] = tmp;
        }
    }

    return ;
}

int main(){
    int nums[] = {3,2,1};
    nextPermutation(nums, sizeof(nums)/sizeof(nums[0]));
    return 0;
}