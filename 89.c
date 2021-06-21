#include <stdlib.h>
#include <string.h>

int* grayCode(int n, int* returnSize){
    *returnSize = 1;
    while (n>0){
        *returnSize = 2 * (*returnSize);
        n--;
    }
    int *ret = (int *)malloc(*returnSize * (sizeof(int)));
    if (ret == NULL)
        return NULL;
    memset(ret, 0, *returnSize);
    ret[0] = 0;
    int r = 0;
    int cur = 1;
    for (int i=1; i<*returnSize; i++){
        ret[i] = cur + ret[r];
        r--;
        if (r < 0){
            cur = 2 * cur;
            r = i;
        }
    }
    return ret;
}

int main(){
    int  returnSize = 0;
    grayCode(3, &returnSize);
    return 0;
}