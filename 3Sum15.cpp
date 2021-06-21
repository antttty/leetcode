#include <stdlib.h>
int cmp(const void* a, const void * b){
    int *argv1 = (int *)a;
    int *argv2 = (int *)b;

    return *argv1 - *argv2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);
    //先不去重
    int **ret = (int **)malloc(numsSize * sizeof(int *));
    int *ColumnSizes = (int *)malloc(numsSize * sizeof(int));
    int i = 0;
    *returnSize = 0;
    for (i ; i < numsSize - 2; i++){
        if (nums[i] > 0)
            return ret;
        else if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        else{
            int l = i+1;
            int r = numsSize - 1;
            while(l < r ){
                if (nums[l] + nums[r] < -nums[i]){
                    l++;
                    while(l+1 < r && nums[l+1] == nums[l]) 
                        l++;
                }else if (nums[l] + nums[r] > -nums[i]){
                    r--;
                    while(r-1 >= l && nums[r-1] == nums[r])
                        r--;
                }else{
                    int *pnode = (int *)malloc(3*sizeof(int));
                    pnode[0] = nums[i]; pnode[1] = nums[l]; pnode[2] = nums[r]; 
                    ret[*returnSize] = pnode;
                    ColumnSizes[(*returnSize)++] = 3;
                    l++;r--;
                }
            }
        }
    }
    *returnColumnSizes = ColumnSizes;
    return ret;
}

int main(){
    int nums[] = {-2,0,1,1,2};
    int num = 0;
    int *p = &num;
    int ** returnColumnSizes = (int **)malloc(sizeof(int *));
    int **ret = threeSum(nums, sizeof(nums)/sizeof(nums[0]), 
        p, returnColumnSizes);
    return 0 ;
}