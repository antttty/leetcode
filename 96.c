#include <stdio.h>

/*计算不同的二叉搜索树个数*/
int numTrees(int n){
    int nums[n+1];
    nums[0] = 1; nums[1] = 1;
    int i = 2;
    for (; i <= n; i++){
        int j = 1;
        nums[i] = 0;//注意初始化为0
        for (; j <= i ; j++){
            nums[i] += nums[j-1] * nums[i-j];
        }

    }
    return nums[n];
}

int main(){
    int ret = numTrees(8);
    printf("ret:%d\n", ret);
    return 0;
}