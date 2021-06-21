#include <stdlib.h>
#include <limits.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int cmp(const void* a, const void* b){
    int *arg1 = (int *)a;
    int *arg2 = (int *)b;

    if (*arg1 < *arg2)
        return -1;
    else if (*arg1 > *arg2)
        return 1;
    else 
        return 0;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr, arrSize, sizeof(int), cmp);//升序
    int index= 0;
    int min = INT_MAX, count = 0;
    for (index = 1; index < arrSize; index++){
        if (abs(arr[index] - arr[index-1]) <= min){
            if (abs(arr[index] - arr[index-1]) == min){
                count++;
            }else{
                min = abs(arr[index] - arr[index-1]);
                count = 1;
            }  
        }
    }

    int **ret = (int **)malloc(count * sizeof(int *));//动态申请二维数组空间
    for (index = 0; index < count; index++){
        ret[index] = (int *)malloc(2*sizeof(int));
    }

    int i = 0;
    **returnColumnSizes = 2;
    *returnSize = count;
    for(index = 0 ; index < arrSize - 1; index++){
        if (abs(arr[index] - arr[index+1]) == min){
            ret[i][0] = min(arr[index], arr[index+1]);
            ret[i][1] = max(arr[index], arr[index+1]);
            i++;
        }
    }
    return ret;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
   
    qsort(arr,arrSize,sizeof(int),cmp);
    int **returnarra = (int **)malloc(sizeof(int*)*arrSize), count = 0;
    int *ColumnSizes = (int*)malloc(sizeof(int)* arrSize);
    //assert(returnarra!=NULL && ColumnSizes!=NULL);

    int different, min = abs(arr[0]-arr[arrSize-1]);
    for(int i = 1; i < arrSize;i++){
        if((different = abs(arr[i] - arr[i-1])) < min){
            min = different;
        }
    }

    for(int i = 1; i < arrSize; i++){
        different = abs(arr[i] - arr[i-1]);
        if(different == min){
            int *pair = (int *)malloc(sizeof(int) * 2);
            pair[0] = arr[i-1];
            pair[1] = arr[i];
            returnarra[count] =pair;
            ColumnSizes[count++] = 2;
        }
    }
    
    *returnSize = count;
    *returnColumnSizes = ColumnSizes;
    return returnarra; 
}
int cmp(const void* num, const void* num2){
    return *(int*)num - *(int*)num2;
}

int main(){
    int nums[] = {1,3,6,10,15};
    int retSize = 0;
    int * returnSize = &retSize;
    int retColumnSizes = 0;
    int *ptr = &retColumnSizes;
    int ** returnColumnSizes = &ptr;
    int **ret = minimumAbsDifference(nums, sizeof(nums)/sizeof(nums[0]), 
    returnSize, returnColumnSizes);
    return 0;
} 