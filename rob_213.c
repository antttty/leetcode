#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
    int     robhelp(int *nums, int low, int high);
    int      sum1 = 0;
    sum1 = robhelp(nums,  2, numsSize-2);//选择了第一个
    int      sum2 = 0;
    sum2 = robhelp(nums,  1, numsSize-1);//没有选择第一个
    return max(sum1, sum2);
}

int robhelp(int *nums, int low, int high)
{
    int dp2 = 0, dp1 = 0, dp = 0;

    int i = low;
    for(; i <= high; i++)
    {
        dp = max(dp2+nums[i], dp1);
        dp2 = dp1;
        dp1 = dp;
    }
    return dp;
}

int main(){
    int pint[5] = {1,2,3,1,2};
    int ret = rob(pint, 5);
    printf("ret :%d\n", ret);
    return 0;
}